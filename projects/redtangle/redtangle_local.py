from algorithm import *
import traceback
import pyautogui

class UserQuit(Exception):
    def __init__(self):
        pass
    
# 2 Player Mode on 1 machine
class RedTangleLocal:
    def __init__(self):
        pygame.init()
        self._window = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
        self._clock = pygame.time.Clock()
        self._redtangle_alg = RedTangleAlgorithm()
        self._winner = ''
        self._run()

    def get_square_color(row, col):
        flag, _ = RedTangleAlgorithm.is_redtangle(row, col)
        return RED if flag else GOLD
    
    def _proc_actions(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                raise UserQuit()
            elif event.type == pygame.MOUSEBUTTONDOWN and not self._winner:
                if event.button == LEFT_CLICK:
                    self._redtangle_alg.select(pygame.mouse.get_pos())
                elif event.button == RIGHT_CLICK:
                    self._redtangle_alg.end_turn()
                elif event.button == SCROLL_UP:
                    self._redtangle_alg.rotate(clockwise=True)
                elif event.button == SCROLL_DOWN:
                    self._redtangle_alg.rotate(clockwise=False)
    
    def _set_caption(self):
        turn = self._redtangle_alg.get_turn()
        winner = self._redtangle_alg.get_winner()
        caption = f"{TITLE}: {turn}'s Turn" if not winner else f"{TITLE}: {winner} Won"
        pygame.display.set_caption(caption)

    def _update_board(self, board):
        for row in range(GRID_SIZE):
            for col in range(GRID_SIZE):
                pygame.draw.rect(self._window, BLACK, 
                                pygame.Rect(col * SQUARE_WIDTH, 
                                row * SQUARE_HEIGHT,
                                SQUARE_WIDTH, SQUARE_HEIGHT))
                pygame.draw.rect(self._window, RedTangleLocal.get_square_color(row, col), 
                                pygame.Rect(col * SQUARE_WIDTH + EDGE_SIZE, 
                                row * SQUARE_HEIGHT + EDGE_SIZE,
                                SQUARE_WIDTH - EDGE_SIZE, SQUARE_HEIGHT - EDGE_SIZE))
                if board[row][col].get_team() != None:
                   board[row][col].draw(self._window, row, col)
        self._clock.tick(FPS)
        pygame.display.update()

    def _run(self):
        try:
            while True: 
                self._proc_actions()
                self._set_caption()
                self._update_board(self._redtangle_alg.get_board())
        
        except UserQuit:
            print('User has requested to stop the application.')
        
        except Exception as e:
            print(f'{traceback.format_exc()}')
        
        finally:
            pygame.quit()

# Runs the Local Game
if __name__ == "__main__":
    RedTangleLocal()