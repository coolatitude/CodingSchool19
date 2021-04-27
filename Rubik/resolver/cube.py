from enum import Enum
import numpy as np
from moves import F, R, U, B, L, D, Right, Down, DownSide

from colorama import Back


class Colors(Enum):
    F = 'RED'
    B = 'ORANGE'
    U = 'GREEN'
    D = 'BLUE'
    R = 'YELLOW'
    L = 'WHITE'


class Faces(Enum):
    L = 2
    U = 4
    F = 8
    D = 16
    R = 32
    B = 64


VisualFormatColors = {
    2: Back.RED,
    4: Back.YELLOW,
    8: Back.GREEN,
    16: Back.WHITE,
    32: Back.LIGHTCYAN_EX,# no ORANGE
    64: Back.BLUE
}

colors = [
    2, 4, 8, 16, 32, 64
]

# F R U B L D


class Cube:

    moves = {
        'F': lambda grid: np.dot(grid, F),
        'R': lambda grid: np.dot(grid, R),
        'U': lambda grid: np.dot(grid, U),
        'B': lambda grid: np.dot(grid, B),
        'L': lambda grid: np.dot(grid, L),
        'D': lambda grid: np.dot(grid, D),
        'F2': lambda grid: np.dot(np.dot(grid, F), DownSide),
        'R2': lambda grid: np.dot(np.dot(grid, R), np.linalg.inv(Down)),
        'U2': lambda grid: np.dot(np.dot(grid, U), np.linalg.inv(Right)),
        'B2': lambda grid: np.dot(np.dot(grid, B), np.linalg.inv(DownSide)),
        'L2': lambda grid: np.dot(np.dot(grid, L), Down),
        'D2': lambda grid: np.dot(np.dot(grid, D), Right),
        'F\'': lambda grid: np.dot(grid, np.linalg.inv(F)),
        'R\'': lambda grid: np.dot(grid, np.linalg.inv(R)),
        'U\'': lambda grid: np.dot(grid, np.linalg.inv(U)),
        'B\'': lambda grid: np.dot(grid, np.linalg.inv(B)),
        'L\'': lambda grid: np.dot(grid, np.linalg.inv(L)),
        'D\'': lambda grid: np.dot(grid, np.linalg.inv(D)),
    }

    @staticmethod
    def invalid_move(self):
        print('Unknown move: ' + self.move)
        exit(0)

    def __init__(self, size):
        self.size = size
        self.grid = []
        self.move = ''
        for c in colors:
            for x in range(size * size):
                self.grid.append(c)
        self.grid = np.array(self.grid)

    visual = [
        [0, 0, 0, 10, 11, 12],
        [0, 0, 0, 15, 14, 13],
        [0, 0, 0, 16, 17, 18],
        [1, 2, 3, 19, 20, 21, 37, 38, 39, 46, 47, 48],
        [6, 5, 4, 24, 23, 22, 42, 41, 40, 51, 50, 49],
        [7, 8, 9, 25, 26, 27, 43, 44, 45, 52, 53, 54],
        [0, 0, 0, 28, 29, 30],
        [0, 0, 0, 33, 32, 31],
        [0, 0, 0, 34, 35, 36]
    ]

    def print(self):
        for visual_schema_line in self.visual:
            line = ''
            for elem in visual_schema_line:
                if elem == 0:
                    line += '  '
                else:
                    line += VisualFormatColors.get(self.grid[elem - 1]) + '  '
            line += Back.RESET
            print(line)
        print()

    def do_move(self, move):
        self.move = move
        action = self.moves.get(move, self.invalid_move)
        self.grid = action(self.grid)
