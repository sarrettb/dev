from constants import *
from piece import *
import random

class RedTangle_Algorithm:
    def __init__(self):
        self.board = [[Piece(None, None) for i in range(GRID_SIZE)] for j in range(GRID_SIZE)]
        self.turn = WHITE
        self.piece_selected = (None, None)
        self.piece_locked = False
        self.must_jump = False
        self.winner = ''
        self.__init_board()

    # Public Methods:
    def get_winner(self):
        return self.winner

    def get_turn(self):
        return 'WHITE' if self.turn == WHITE else 'BLACK'
    
    def get_board(self):
        return self.board

    def end_turn(self):
        self.turn = BLACK if self.turn == WHITE else WHITE
        self.piece_selected = (None, None)
        self.piece_locked = False
        self.must_jump = False

    # Selct a Piece or Select Empty Square to move to
    def select(self, pos):
        col, row = RedTangle_Algorithm.__get_row_col(pos)
        # Can only rotate if piece is locked
        if not self.piece_locked:
            if self.board[row][col].get_team() == self.turn:
                self.piece_selected = (row, col)
            elif self.board[row][col].get_team() == None:
                self.__move((row, col))
            # Opponents Piece
            else:
                _from = self.piece_selected
                if self.__valid_suicide(self.piece_selected, (row, col)):
                    if self.__move((row, col)):
                        self.__delete_pieces([_from, (row, col)])
                        self.end_turn()
    
    def rotate(self, clockwise):
        if self.piece_selected == (None, None):
            return
        row, col = self.piece_selected
        if not self.must_jump:
            self.board[row][col].rotate(clockwise)
        self.piece_locked = True

    # Private Methods:
    def __init_board(self):
        # Generate Pieces
        sides = [0, 1, 1, 2, 2, 2, 3, 4]
        black_pieces = []
        white_pieces = []
        for num_sides in sides:
            black_ori = []
            white_ori = []
            for i in range(ORIENTATIONS):
                black_ori.append(BLACK if i < num_sides else WHITE)
                white_ori.append((WHITE if i < num_sides else BLACK))
            black_pieces.append(Piece(BLACK, black_ori))
            white_pieces.append(Piece(WHITE, white_ori))
        
        random.shuffle(black_pieces)
        random.shuffle(white_pieces)
        idx = 0
        # Insert into board
        for row in range(RECT_HEIGHT):
            for col in range(RECT_WIDTH):
                self.board[row][col + 2] = white_pieces[idx]
                self.board[GRID_SIZE - 1 - row][col + 2] = black_pieces[idx]
                idx += 1
    
    # Flags
    
    def is_redtangle(row, col):
        if (col >= 2 and col < GRID_SIZE - 2):
            if (row < 2):
                return (True, TOP_RECT)
            if (row >= GRID_SIZE - 2):
                return (True, BOTTOM_RECT)
        return (False, None)
    def __is_blocked(self, _from, to):
        # Orientations are in the order [LEFT, BOTTOM, RIGHT, TOP]
        from_ori = self.board[_from[0]][_from[1]].get_orientation()
        to_ori = self.board[to[0]][to[1]].get_orientation()

        # Moving Up
        if (_from[0] - to[0] > 0):
            print('Moving Up')
            return from_ori[3] == to_ori[1]
        
        # Moving Down
        elif (_from[0] - to[0] < 0):
            print('Moving Down')
            return from_ori[1] == to_ori[3]
        
        # Moving Right
        elif (_from[1] - to[1] < 0):
            print('Moving Right')
            return from_ori[2] == to_ori[0]
        
        # Moving Left
        elif(_from[1] - to[1] > 0):
            print('Moving Left')
            return from_ori[0] == to_ori[2]

        # Default -- Bug if occurs (TODO return error)
        return False
    
    # Returns (is_eight_adj, is_diagnol)
    def __is_eight_adj(_from, to):
        return ((abs(_from[0] - to[0]) <= 1 and
                abs(_from[1] - to[1]) <= 1), 
                (abs(_from[0] - to[0]) == 1 and
                abs(_from[1] - to[1]) == 1))

    def __is_winning_move(self, to):
        OPPONENTS_RECT = BOTTOM_RECT if self.turn == WHITE else TOP_RECT
        to_redtangle = RedTangle_Algorithm.is_redtangle(to[0], to[1])
        return to_redtangle[0] and to_redtangle[1] == OPPONENTS_RECT

     # Jump is valid if it is in one direction
    def __valid_jump(self, _from, to):
        return _from[0] - to[0] == 0 or _from[1] - to[1] == 0

    def __valid_suicide(self, _from, to):
       # Vertical Attack
       if _from[1] == to[1]:
            if to[0] == 0 or to[0] == GRID_SIZE - 1:
                return not self.__is_blocked(_from, to)
       # Horizontal Attack
       if _from[0] == to[0]:
            if to[1] == 0 or to[1] == GRID_SIZE - 1:
                return not self.__is_blocked(_from, to)
       return False

    # Private Accessors/Mutators 
    def __get_row_col(pos):
        return (pos[0] // SQUARE_WIDTH, pos[1] // SQUARE_HEIGHT)
    
    def __set_winner(self):
        self.winner = self.get_turn()

    # Processing
    def __swap_pieces(self, pos1, pos2):
        self.board[pos1[0]][pos1[1]], self.board[pos2[0]][pos2[1]] = self.board[pos2[0]][pos2[1]], self.board[pos1[0]][pos1[1]]
    
    def __make_move(self, to):
        self.__swap_pieces(self.piece_selected, to)
        self.piece_selected = to
        self.piece_locked = True

    def __move(self, to):
        row, col = to
        # Check a piece has been selected and moving to empty space
        if self.piece_selected != (None, None):
            # Handle the case for moving to eight adjacent
            eight_adj, diagnol = RedTangle_Algorithm.__is_eight_adj(self.piece_selected, (row, col))
            winning_move = self.__is_winning_move((row, col))
            if eight_adj and not self.must_jump:
                if diagnol:
                    if not winning_move:
                        self.__make_move((row, col))
                        return True
                else:
                    if winning_move:
                        self.__set_winner()
                    self.__make_move((row, col))
                    return True
            
            # Perform a Jump
            else:
                cap_vert_pieces = self.__vertical_jump(self.piece_selected, (row, col))
                cap_horz_pieces = self.__horizontal_jump(self.piece_selected, (row, col))
                if len(cap_horz_pieces + cap_vert_pieces) > 0 and self.__valid_jump(self.piece_selected, (row, col)):
                    self.__make_move((row, col))
                    self.__delete_pieces(cap_horz_pieces + cap_vert_pieces)
                    self.piece_locked = False # Unlock Piece because it can double jump
                    self.must_jump = True # Piece must jump if it moves
                    if winning_move:
                        self.__set_winner()
                    return True
            return False
    
    def __vertical_jump(self, _from, to):
        if _from[0] == to[0]:
            return []
        prev = [_from[0], _from[1]]
        a = 1 if to[0] - _from[0] > 0 else -1
        curr_row = _from[0] + a
        captured_pieces = []
        own_team = self.board[_from[0]][_from[1]].get_team()

        while curr_row != to[0]:
            print(f'Curr Piece: {self.board[curr_row][_from[1]]}')
            jumped_piece_team = self.board[curr_row][_from[1]].get_team()
            if jumped_piece_team == None or jumped_piece_team == own_team or self.__is_blocked(prev, (curr_row, _from[1])):
                captured_pieces.clear()
                break
            else:
                captured_pieces.append((curr_row, _from[1]))
            prev[0] = curr_row
            curr_row += a
        return captured_pieces
    
    def __horizontal_jump(self, _from, to):
        if _from[1] == to[1]:
            return []

        prev = [_from[0], _from[1]]
        a = 1 if to[1] - _from[1] > 0 else -1
        curr_col = _from[1] + a
        captured_pieces = []
        own_team = self.board[_from[0]][_from[1]].get_team()
        while curr_col != to[1]:
            jumped_piece_team = self.board[_from[0]][curr_col].get_team()
            if jumped_piece_team == None or jumped_piece_team == own_team or self.__is_blocked(prev, (_from[0], curr_col)):
                captured_pieces.clear()
                break
            else:
                captured_pieces.append((_from[0], curr_col))
            prev[1] = curr_col
            curr_col += a
        return captured_pieces

    def __delete_pieces(self, pieces_to_delete):
        for pos in pieces_to_delete:
            self.board[pos[0]][pos[1]] = Piece(None, None)

class RedTangle_Display:
    def __init__():
        pass
    
    def update_board(self, board):
        pass
    
    def run(self):
        pass

class RedTangle_LocalDisplay(RedTangle_Display):
    def __init__(self):
        pygame.init()
        self.window = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
        self.clock = pygame.time.Clock()
        self.redtangle_alg = RedTangle_Algorithm()

    def __get_square_color(row, col):
        flag, _ = RedTangle_Algorithm.is_redtangle(row, col)
        return RED if flag else GOLD

    def update_board(self, board):
        for row in range(GRID_SIZE):
            for col in range(GRID_SIZE):
                pygame.draw.rect(self.window, BLACK, 
                                pygame.Rect(col * SQUARE_WIDTH, 
                                row * SQUARE_HEIGHT,
                                SQUARE_WIDTH, SQUARE_HEIGHT))
                pygame.draw.rect(self.window, RedTangle_LocalDisplay.__get_square_color(row, col), 
                                pygame.Rect(col * SQUARE_WIDTH + EDGE_SIZE, 
                                row * SQUARE_HEIGHT + EDGE_SIZE,
                                SQUARE_WIDTH - EDGE_SIZE, SQUARE_HEIGHT - EDGE_SIZE))
                if board[row][col].get_team() != None:
                   board[row][col].draw(self.window, row, col)
        pygame.display.update()

    def run(self):
        running = True
        while running: 
            self.clock.tick(FPS)
            turn = self.redtangle_alg.get_turn()
            winner = self.redtangle_alg.get_winner()
            caption = f"{TITLE}: {turn}'S TURN" if not winner else f"{TITLE}: {winner} WON"
            pygame.display.set_caption(caption)
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.MOUSEBUTTONDOWN and not winner:
                    if event.button == LEFT_CLICK:
                        print('Left Click Detected')
                        self.redtangle_alg.select(pygame.mouse.get_pos())
                    elif event.button == RIGHT_CLICK:
                        print('Right Click Detected')
                        self.redtangle_alg.end_turn()
                    elif event.button == SCROLL_UP:
                        print('Scroll Up')
                        self.redtangle_alg.rotate(clockwise=True)
                    elif event.button == SCROLL_DOWN:
                        print('Scroll Down')
                        self.redtangle_alg.rotate(clockwise=False)

            self.update_board(self.redtangle_alg.get_board())
        pygame.quit()