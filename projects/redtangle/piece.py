from constants import *
import json
from json import JSONDecoder

class Piece:
    def __init__(self, color, orien):
        self.team_color = color
        self.orientation = orien

    def get_team(self):
        return self.team_color

    def get_orientation(self):
        return self.orientation

    def is_all_black_piece(self):
        if self.team_color != BLACK:
            return False
        for ori_color in self.orientation:
            if ori_color != BLACK:
                return False
        return True
    
    def rotate(self, clockwise):
        if clockwise:
            self.orientation[:]=self.orientation[1:ORIENTATIONS]+self.orientation[0:1]
        else:
            self.orientation = (self.orientation[len(self.orientation) - 1:len(self.orientation)]
                                + self.orientation[0:len(self.orientation) - 1])

    def draw(self, win, row, col):
        rect = pygame.Rect(col * SQUARE_WIDTH + PIECE_WIDTH_OFFSET, 
                                row * SQUARE_HEIGHT + PIECE_HEIGHT_OFFSET,
                                PIECE_WIDTH, PIECE_HEIGHT)
        pygame.draw.rect(win, BLACK, rect)
        points = []
        # Orientations are in the order (LEFT, BOTTOM, RIGHT, TOP)
        for c, i in zip(self.orientation, range(4)):
            match i:
                case 0:
                    points = [(rect.left, rect.top), (rect.left, rect.bottom), 
                            (rect.centerx - X_OFFSET, rect.centery + Y_OFFSET ), 
                            (rect.centerx - X_OFFSET, rect.centery - Y_OFFSET)]
                case 1:
                    points = [(rect.left, rect.bottom), (rect.right, rect.bottom),
                            (rect.centerx - X_OFFSET, rect.centery - Y_OFFSET),
                            (rect.centerx + X_OFFSET, rect.centery - Y_OFFSET)]
                case 2:
                    points = [(rect.right, rect.bottom), (rect.right, rect.top),
                            (rect.centerx + X_OFFSET, rect.centery - Y_OFFSET),
                            (rect.centerx + X_OFFSET, rect.centery + Y_OFFSET)]
                case 3:
                    points = [(rect.left, rect.top), (rect.right, rect.top),
                            (rect.centerx - X_OFFSET, rect.centery + Y_OFFSET),
                            (rect.centerx + X_OFFSET, rect.centery + Y_OFFSET)]
            circle_edge_color, circle_edge_thickenss = (WHITE, 1) if self.is_all_black_piece() else (BLACK, THICKNESS)
            pygame.draw.polygon(win, c, points)
            pygame.draw.circle(win, circle_edge_color, rect.center, RADIUS + circle_edge_thickenss)
            pygame.draw.circle(win, self.team_color, rect.center, RADIUS)