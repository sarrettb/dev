import constants
from algorithm import RedTangleAlgorithm
from concurrent import futures
from proto import redtangle_pb2_grpc, redtangle_pb2
import grpc
import pyautogui
import json
import traceback

# Server to run the RedTangle Game Remotely 
# Only two players can be connected
class RedTangleServer(redtangle_pb2_grpc.RedTangleServicer):
    def __init__(self, port=50051):
        self._port = str(port)
        self._server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
        self._redtangle = RedTangleAlgorithm()
        self._players = {}
        self._server_status = True # Flag to know if an exception has occured (True is good state)
        self.launch_server()

    def launch_server(self):
        print('Launching Server...')
        redtangle_pb2_grpc.add_RedTangleServicer_to_server(self, self._server)
        print(f"[::]:{self._port}")
        self._server.add_insecure_port(f"[::]:{self._port}")
        self._server.start()
        pyautogui.confirm(title='Redtangle', text='Server is Running', buttons=['Stop Server']) 
        self._server.stop(grace=None)
        self._server.wait_for_termination()
        print('Server Stopped.')

    def get_opponent(self, username):
        for player in self._players:
            if player != username:
                return player
        return ''

    def get_turn(self):
        return self._redtangle.get_turn()
    
    def get_winner(self):
       return self._redtangle.get_winner()
    
    def get_server_status(self):
        return redtangle_pb2.NO_ERROR if self._server_status else redtangle_pb2.SERVER_ERROR

    def __color_to_str(color):
        if color == constants.WHITE:
            return 'White'
        if color == constants.BLACK:
            return 'Black'
        return ''

    # Encode Board as JSON string
    def encode_board(self):
        board = self._redtangle.get_board()
        my_dict = {}
        for row in range(constants.GRID_SIZE):
            for col in range(constants.GRID_SIZE):
                team_color = RedTangleServer.__color_to_str(board[row][col].get_team())
                ori = [ RedTangleServer.__color_to_str(ori_color) for ori_color in board[row][col].get_orientation() ]
                my_dict[str((row, col))] = {
                                                'team_color': team_color,
                                                'orientation': ori
                                           }
                                           
        return json.dumps(my_dict, indent=4)
    
    def get_game_status(self, username):
        return redtangle_pb2.GameStatus(opponent=self.get_opponent(username),
                                        turn=self.get_turn(),
                                    winner=self.get_winner(),
                                    board=self.encode_board())
    
    def invalid_connection():
        return redtangle_pb2.ConnectionResponse(team_color='None',
                                                connected=False,
                                                status=redtangle_pb2.Status(turn='None',
                                                                            winner='None',
                                                                            board='None')
                                                )

    def Connect(self, request, context):
        try:
            if request.username in self._players:
                print(f'Hi {request.username}, this username already exists.')
                return redtangle_pb2.ConnectionResponse(status=redtangle_pb2.Status(server_status=redtangle_pb2.USER_EXISTS))
            
            elif len(self._players) >= 2:
                print(f'Hi {request.username}, the game is full. Unable to connect more clients.')
                return redtangle_pb2.ConnectionResponse(status=redtangle_pb2.Status(server_status=redtangle_pb2.GAME_FULL))
            
            else:
                print(f'Hi {request.username}, you are connected to the server.')
                self._players[request.username] = 'White' if len(self._players) == 0 else 'Black'
                return redtangle_pb2.ConnectionResponse(team_color=self._players[request.username],
                                                        status=redtangle_pb2.Status(game_status=self.get_game_status(request.username),
                                                                                    server_status=self.get_server_status())
                                                        )
                                                        
        except Exception as e:
            self._server_status = False
            print(f'{traceback.format_exc()}')
            return redtangle_pb2.ConnectionResponse(status=redtangle_pb2.Status(server_status=redtangle_pb2.SERVER_ERROR))


    def GetStatus(self, request, context):
        try:
            return redtangle_pb2.Status(game_status=self.get_game_status(request.username),
                                        server_status=self.get_server_status())
        
        except Exception as e:
            self._server_status = False
            print(f'{traceback.format_exc()}')
            return redtangle_pb2.Status(server_status=redtangle_pb2.SERVER_ERROR)

    def Select(self, request, context):
        try:
            if self._players[request.username.username] == self._redtangle.get_turn() and len(self._players) == 2:
                self._redtangle.select((request.position.y, request.position.x))

            return redtangle_pb2.Status(game_status=self.get_game_status(request.username.username),
                                        server_status=self.get_server_status())
        
        except Exception as e:
            self._server_status = False
            print(f'{traceback.format_exc()}')
            return redtangle_pb2.Status(server_status=redtangle_pb2.SERVER_ERROR)
    
    def Rotate(self, request, context):
        try:
            if self._players[request.username.username] == self._redtangle.get_turn() and len(self._players) == 2:
                self._redtangle.rotate(clockwise=request.clockwise_rotation)

            return redtangle_pb2.Status(game_status=self.get_game_status(request.username.username),
                                        server_status=self.get_server_status())
        
        except Exception as e:
            self._server_status = False
            print(f'{traceback.format_exc()}')
            return redtangle_pb2.Status(server_status=redtangle_pb2.SERVER_ERROR)
        
    def EndTurn(self, request, context):
        try:
            if self._players[request.username] == self._redtangle.get_turn() and len(self._players) == 2:
                self._redtangle.end_turn()
            return redtangle_pb2.Status(game_status=self.get_game_status(request.username),
                                        server_status=self.get_server_status())
        
        except Exception as e:
            self._server_status = False
            print(f'{traceback.format_exc()}')
            return redtangle_pb2.Status(server_status=redtangle_pb2.SERVER_ERROR)
    
    def Disconnect(self, request, context):
        try:
            self._players.pop(request.username)
            self._redtangle = RedTangleAlgorithm()
            print(f'Bye {request.username}, you have disconnected from the server.')
            return redtangle_pb2.StatusCode(code=self.get_server_status())
        
        except Exception as e:
            self._server_status = False
            print(f'{traceback.format_exc()}')
            return redtangle_pb2.ConnectionResponse(status=redtangle_pb2.Status(server_status=redtangle_pb2.SERVER_ERROR))

# Runs the Server
if __name__ == "__main__":
    RedTangleServer()