from algorithm import *

# 2 Player Mode on 1 machine
class RedTangleLocal:
    def __init__(self):
        pygame.init()
        self.window = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
        self.clock = pygame.time.Clock()
        self.redtangle_alg = RedTangleAlgorithm()

    def get_square_color(row, col):
        flag, _ = RedTangleAlgorithm.is_redtangle(row, col)
        return RED if flag else GOLD

    def _update_board(self, board):
        for row in range(GRID_SIZE):
            for col in range(GRID_SIZE):
                pygame.draw.rect(self.window, BLACK, 
                                pygame.Rect(col * SQUARE_WIDTH, 
                                row * SQUARE_HEIGHT,
                                SQUARE_WIDTH, SQUARE_HEIGHT))
                pygame.draw.rect(self.window, RedTangleLocal.get_square_color(row, col), 
                                pygame.Rect(col * SQUARE_WIDTH + EDGE_SIZE, 
                                row * SQUARE_HEIGHT + EDGE_SIZE,
                                SQUARE_WIDTH - EDGE_SIZE, SQUARE_HEIGHT - EDGE_SIZE))
                if board[row][col].get_team() != None:
                   board[row][col].draw(self.window, row, col)
        pygame.display.update()

    def run(self):
        running = True
        while running: 
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
            self.clock.tick(FPS)
            turn = self.redtangle_alg.get_turn()
            winner = self.redtangle_alg.get_winner()
            caption = f"{TITLE}: {turn}'S TURN" if not winner else f"{TITLE}: {winner} WON"
            pygame.display.set_caption(caption)
            self._update_board(self.redtangle_alg.get_board())
        pygame.quit()

# Runs the Local Game
if __name__ == "__main__":
    RedTangleLocal()