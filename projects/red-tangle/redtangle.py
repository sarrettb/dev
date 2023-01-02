import pygame
import random
import math

class Constants:
    FPS = 60
    LEFT_CLICK = 1
    RIGHT_CLICK = 3
    SCROLL_UP = 4
    SCROLL_DOWN = 5
    TITLE = 'REDTANGLE'
    TOP_RECT = 0
    BOTTOM_RECT = 1
    RECT_WIDTH = 4
    RECT_HEIGHT = 2
    GRID_SIZE = 8
    EDGE_SIZE = 2
    SCREEN_WIDTH = 600
    SCREEN_HEIGHT = 600
    SQUARE_WIDTH = SCREEN_WIDTH // GRID_SIZE
    SQUARE_HEIGHT = SCREEN_HEIGHT // GRID_SIZE
    PIECE_HEIGHT_OFFSET = SQUARE_HEIGHT // 5
    PIECE_WIDTH_OFFSET = SQUARE_WIDTH // 5
    PIECE_HEIGHT = int(0.85 * SQUARE_HEIGHT) - PIECE_HEIGHT_OFFSET
    PIECE_WIDTH = int(0.85 * SQUARE_WIDTH) - PIECE_WIDTH_OFFSET
    ORIENTATIONS = 4
    RADIUS = int(PIECE_WIDTH * 0.15)
    THICKNESS = 2
    PHI = math.atan(PIECE_HEIGHT / PIECE_WIDTH)
    X_OFFSET = RADIUS * math.cos(PHI)
    Y_OFFSET = RADIUS * math.sin(PHI)
    RED = pygame.Color(255, 0, 0)
    GOLD = pygame.Color(255, int(255 * 0.843), 0) 
    BLACK = pygame.Color(0, 0, 0)
    WHITE = pygame.Color(255, 255, 255)


class Piece:
    def __init__(self, color, orien):
        self.team_color = color
        self.orientation = orien 

    def get_team(self):
        return self.team_color

    def get_orientation(self):
        return self.orientation

    def is_all_black_piece(self):
        if self.team_color != Constants.BLACK:
            return False
        for ori_color in self.orientation:
            if ori_color != Constants.BLACK:
                return False
        return True
    
    def rotate(self, clockwise):
        if clockwise:
            self.orientation[:]=self.orientation[1:Constants.ORIENTATIONS]+self.orientation[0:1]
        else:
            self.orientation = (self.orientation[len(self.orientation) - 1:len(self.orientation)]
                                + self.orientation[0:len(self.orientation) - 1])

    def draw(self, win, row, col):
        rect = pygame.Rect(col * Constants.SQUARE_WIDTH + Constants.PIECE_WIDTH_OFFSET, 
                                row * Constants.SQUARE_HEIGHT + Constants.PIECE_HEIGHT_OFFSET,
                                Constants.PIECE_WIDTH, Constants.PIECE_HEIGHT)
        pygame.draw.rect(win, Constants.BLACK, rect)
        points = []
        # Orientations are in the order (LEFT, BOTTOM, RIGHT, TOP)
        for c, i in zip(self.orientation, range(4)):
            match i:
                case 0:
                    points = [(rect.left, rect.top), (rect.left, rect.bottom), 
                            (rect.centerx - Constants.X_OFFSET, rect.centery + Constants.Y_OFFSET ), 
                            (rect.centerx - Constants.X_OFFSET, rect.centery - Constants.Y_OFFSET)]
                case 1:
                    points = [(rect.left, rect.bottom), (rect.right, rect.bottom),
                            (rect.centerx - Constants.X_OFFSET, rect.centery - Constants.Y_OFFSET),
                            (rect.centerx + Constants.X_OFFSET, rect.centery - Constants.Y_OFFSET)]
                case 2:
                    points = [(rect.right, rect.bottom), (rect.right, rect.top),
                            (rect.centerx + Constants.X_OFFSET, rect.centery - Constants.Y_OFFSET),
                            (rect.centerx + Constants.X_OFFSET, rect.centery + Constants.Y_OFFSET)]
                case 3:
                    points = [(rect.left, rect.top), (rect.right, rect.top),
                            (rect.centerx - Constants.X_OFFSET, rect.centery + Constants.Y_OFFSET),
                            (rect.centerx + Constants.X_OFFSET, rect.centery + Constants.Y_OFFSET)]
            circle_edge_color, circle_edge_thickenss = (Constants.WHITE, 1) if self.is_all_black_piece() else (Constants.BLACK, Constants.THICKNESS)
            pygame.draw.polygon(win, c, points)
            pygame.draw.circle(win, circle_edge_color, rect.center, Constants.RADIUS + circle_edge_thickenss)
            pygame.draw.circle(win, self.team_color, rect.center, Constants.RADIUS)

class Game: 
    def __init__(self, win):
        self.window = win
        self.board = [[Piece(None, None) for i in range(Constants.GRID_SIZE)] for j in range(Constants.GRID_SIZE)]
        self.init_board()
        self.white_turn = True
        self.piece_selected = (None, None)
        self.winner = (None, None)
        self.piece_locked = False
        self.moved = False

    def get_winner(self):
        return self.winner

    def get_turn(self):
        return 'WHITE' if self.white_turn else 'BLACK'

    def is_redtangle(row, col):
        if (col >= 2 and col < Constants.GRID_SIZE - 2):
            if (row < 2):
                return (True, Constants.TOP_RECT)
            if (row >= Constants.GRID_SIZE - 2):
                return (True, Constants.BOTTOM_RECT)
        return (False, None)
    
    def is_blocked(self, _from, to):
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

    def get_square_color(row, col):
        flag, _ = Game.is_redtangle(row, col)
        return Constants.RED if flag else Constants.GOLD
    
    def get_row_col(pos):
        return (pos[0] // Constants.SQUARE_WIDTH, pos[1] // Constants.SQUARE_HEIGHT)
    
    def swap_pieces(self, pos1, pos2):
        self.board[pos1[0]][pos1[1]], self.board[pos2[0]][pos2[1]] = self.board[pos2[0]][pos2[1]], self.board[pos1[0]][pos1[1]]

    # Returns (eight_adj_flag, diagnol_flag)
    def is_eight_adj(_from, to):
        return ((abs(_from[0] - to[0]) <= 1 and
                abs(_from[1] - to[1]) <= 1), 
                (abs(_from[0] - to[0]) == 1 and
                abs(_from[1] - to[1]) == 1))
    
    def init_board(self):
        sides = [0, 1, 1, 2, 2, 2, 3, 4]
        black_pieces = []
        white_pieces = []
        for num_sides in sides:
            black_ori = []
            white_ori = []
            for i in range(Constants.ORIENTATIONS):
                black_ori.append(Constants.BLACK if i < num_sides else Constants.WHITE)
                white_ori.append((Constants.WHITE if i < num_sides else Constants.BLACK))
            black_pieces.append(Piece(Constants.BLACK, black_ori))
            white_pieces.append(Piece(Constants.WHITE, white_ori))
        
        random.shuffle(black_pieces)
        random.shuffle(white_pieces)
        idx = 0
        for row in range(Constants.RECT_HEIGHT):
            for col in range(Constants.RECT_WIDTH):
                self.board[row][col + 2] = white_pieces[idx]
                self.board[Constants.GRID_SIZE - 1 - row][col + 2] = black_pieces[idx]
                idx += 1

    def select(self, pos, rotate=(False, False), double_jump=False):
        col, row = Game.get_row_col(pos)
        _from = self.piece_selected
        selecting_piece = not (rotate[0] or double_jump)
        teams_turn = Constants.WHITE if self.white_turn else Constants.BLACK
        selected_team = self.board[row][col].get_team()

        # Black or White selected empty space
        if selected_team == None:
            if self.piece_selected != (None, None):
                self.move((row, col), double_jump)
        
        # Selected its own piece
        elif selected_team == teams_turn:
            if selecting_piece:
                if not self.piece_locked:
                  self.piece_locked = True
                  self.piece_selected = (row, col)
                
                elif (row, col) == self.piece_selected:
                    self.make_move((row, col), double_jump)

            elif self.piece_locked:
                if rotate[0] and self.moved:
                    self.board[row][col].rotate(rotate[1])
                    
        # Selected opposite team (Only valid case: jumping off the board to capture piece)
        else:
            if self.valid_suicide(self.piece_selected, (row, col)):
                print('Valid Suicide')
                if self.move((row, col)):
                    print('Valid Move')
                    self.delete_pieces([_from, (row, col)])
                
        self.debug()
    
    def make_move(self, to, double_jump):
        self.swap_pieces(self.piece_selected, to)
        self.white_turn = self.white_turn if double_jump else not self.white_turn
        self.piece_selected = to if double_jump else (None, None)
        self.piece_locked = double_jump
        self.moved = double_jump

    def check_winner(self):
        for row in range(Constants.RECT_HEIGHT):
            for col in range(Constants.RECT_WIDTH):
                if self.board[row][col + 2].get_team() == Constants.BLACK:
                    self.winner = (True, 'Black')
                    break
                if self.board[Constants.GRID_SIZE - 1 - row][col + 2].get_team() == Constants.WHITE:
                    self.winner = (True, 'White')
                    break

    def move(self, to, double_jump):
        success = False
        eight_adj, diag = Game.is_eight_adj(self.piece_selected, to)
        if eight_adj and not self.moved:
            print('Is 8-adj')
            red_tangle_flag, red_tangle_type = Game.is_redtangle(to[0], to[1])
            red_tangle_flag = red_tangle_flag and red_tangle_type == (Constants.BOTTOM_RECT if self.white_turn else Constants.TOP_RECT)
            # Red Tangle Flag -> Attempting to enter opponents redtangle
            if red_tangle_flag:
                if not diag:
                    self.make_move(to, double_jump)
                    success = True
            else:
                self.make_move(to, double_jump)
                success = True
        
        # Attempting a Jump
        elif not eight_adj:
           valid_vert_jump, cap_vert_pieces = self.vertical_jump(self.piece_selected, to)
           valid_horz_jump, cap_horz_pieces = self.horizontal_jump(self.piece_selected, to)
           self.delete_pieces(cap_vert_pieces + cap_horz_pieces)
           if valid_horz_jump and valid_vert_jump:
              self.make_move(to, double_jump)
              success = True
           
        self.check_winner()
        return success
    
    def vertical_jump(self, _from, to):
        if _from[0] == to[0]:
            return (True, [])
        prev = [_from[0], _from[1]]
        a = 1 if to[0] - _from[0] > 0 else -1
        curr_row = _from[0] + a
        valid_jump = True
        captured_pieces = []
        own_team = self.board[_from[0]][_from[1]].get_team()

        while curr_row != to[0] and valid_jump:
            print(f'Curr Piece: {self.board[curr_row][_from[1]]}')
            jumped_piece_team = self.board[curr_row][_from[1]].get_team()
            if jumped_piece_team == None or jumped_piece_team == own_team:
                valid_jump = False
            elif self.is_blocked(prev, (curr_row, _from[1])):
                valid_jump = False
                captured_pieces.clear()
            else:
                captured_pieces.append((curr_row, _from[1]))
            prev[0] = curr_row
            curr_row += a
        return (valid_jump, captured_pieces)
    
    def horizontal_jump(self, _from, to):
        if _from[1] == to[1]:
            return (True, [])

        prev = [_from[0], _from[1]]
        a = 1 if to[1] - _from[1] > 0 else -1
        curr_col = _from[1] + a
        valid_jump = True
        captured_pieces = []
        own_team = self.board[_from[0]][_from[1]].get_team()
        while curr_col != to[1] and valid_jump:
            jumped_piece_team = self.board[_from[0]][curr_col].get_team()
            if jumped_piece_team == None or jumped_piece_team == own_team:
                valid_jump = False
            elif self.is_blocked(prev, (_from[0], curr_col)):
                valid_jump = False
                captured_pieces.clear()
            else:
                captured_pieces.append((_from[0], curr_col))
            prev[1] = curr_col
            curr_col += a
        return (valid_jump, captured_pieces)

    def delete_pieces(self, pieces_to_delete):
        print(f'Deleting Pieces {pieces_to_delete}')
        for pos in pieces_to_delete:
            self.board[pos[0]][pos[1]] = Piece(None, None)

    def update(self):
        for row in range(Constants.GRID_SIZE):
            for col in range(Constants.GRID_SIZE):
                pygame.draw.rect(self.window, Constants.BLACK, 
                                pygame.Rect(col * Constants.SQUARE_WIDTH, 
                                row * Constants.SQUARE_HEIGHT,
                                Constants.SQUARE_WIDTH, Constants.SQUARE_HEIGHT))
                pygame.draw.rect(self.window, Game.get_square_color(row, col), 
                                pygame.Rect(col * Constants.SQUARE_WIDTH + Constants.EDGE_SIZE, 
                                row * Constants.SQUARE_HEIGHT + Constants.EDGE_SIZE,
                                Constants.SQUARE_WIDTH - Constants.EDGE_SIZE, Constants.SQUARE_HEIGHT - Constants.EDGE_SIZE))
                if self.board[row][col].get_team() != None:
                    self.board[row][col].draw(self.window, row, col)
        pygame.display.update()

    def valid_suicide(self, _from, to):
       print(f'Suicide Move From {_from} to {to}')
       # Vertical Attack
       if _from[1] == to[1]:
            if to[0] == 0 or to[0] == Constants.GRID_SIZE - 1:
                return not self.is_blocked(_from, to)
       # Horizontal Attack
       if _from[0] == to[0]:
            if to[1] == 0 or to[1] == Constants.GRID_SIZE - 1:
                return not self.is_blocked(_from, to)
       return False

    def debug(self):
        print(f'White Turn: {self.white_turn} ')
        str_locked = 'Locked' if self.piece_locked else 'Unlocked'
        print(f'Piece Selected: {self.piece_selected} is { str_locked }')

class RedTangle:
    def run():
        running = True
        window = pygame.display.set_mode((Constants.SCREEN_WIDTH, Constants.SCREEN_HEIGHT))
        clock = pygame.time.Clock()
        red_tangle = Game(window)
        while running and not red_tangle.get_winner()[1]: 
            clock.tick(Constants.FPS)
            pygame.display.set_caption(f"{Constants.TITLE}: {red_tangle.get_turn()}'S TURN")
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.MOUSEBUTTONDOWN:
                    if event.button == Constants.LEFT_CLICK:
                        print('Left Click Detected')
                        red_tangle.select(pygame.mouse.get_pos())
                    elif event.button == Constants.RIGHT_CLICK:
                        print('Right Click Detected')
                        red_tangle.select(pygame.mouse.get_pos(), double_jump=True)
                    elif event.button == Constants.SCROLL_UP:
                        print('Scroll Up')
                        red_tangle.select(pygame.mouse.get_pos(), rotate=(True, True))
                    elif event.button == Constants.SCROLL_DOWN:
                        red_tangle.select(pygame.mouse.get_pos(), rotate=(True, False))
                        print('Scroll Down')

            red_tangle.update()
        print(red_tangle.get_winner()[0] + ' Won')
        pygame.quit()

RedTangle.run()