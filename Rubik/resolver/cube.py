from enum import Enum
import numpy as np
from moves import F, R, U, B, L, D, Right, Down, DownSide

from colorama import Back


class Moves:
    F2 = 'F2'
    R2 = 'R2'
    U2 = 'U2'
    B2 = 'B2'
    L2 = 'L2'
    D2 = 'D2'
    F = 'F'
    R = 'R'
    U = 'U'
    B = 'B'
    L = 'L'
    D = 'D'
    BF = 'F\''
    BR = 'R\''
    BU = 'U\''
    BB = 'B\''
    BL = 'L\''
    BD = 'D\''


class Faces(Enum):
    L = 2
    U = 4
    F = 8
    D = 16
    R = 32
    B = 64


VisualFormatColors = {
    2: Back.RED,
    4: Back.LIGHTYELLOW_EX,
    8: Back.LIGHTGREEN_EX,
    16: Back.LIGHTWHITE_EX,
    32: Back.LIGHTCYAN_EX,# no ORANGE
    64: Back.BLUE
}

colors = [
    # L U F  D   R   B
    2, 4, 8, 16, 32, 64
]


class Cube:

    moves = {
        Moves.F: lambda grid: np.dot(grid, F),
        Moves.R: lambda grid: np.dot(grid, R),
        Moves.U: lambda grid: np.dot(grid, U),
        Moves.B: lambda grid: np.dot(grid, B),
        Moves.L: lambda grid: np.dot(grid, L),
        Moves.D: lambda grid: np.dot(grid, D),
        Moves.F2: lambda grid: np.dot(np.dot(grid, F), DownSide),
        Moves.R2: lambda grid: np.dot(np.dot(grid, R), np.linalg.inv(Down)),
        Moves.U2: lambda grid: np.dot(np.dot(grid, U), np.linalg.inv(Right)),
        Moves.B2: lambda grid: np.dot(np.dot(grid, B), np.linalg.inv(DownSide)),
        Moves.L2: lambda grid: np.dot(np.dot(grid, L), Down),
        Moves.D2: lambda grid: np.dot(np.dot(grid, D), Right),
        Moves.BF: lambda grid: np.dot(grid, np.linalg.inv(F)),
        Moves.BR: lambda grid: np.dot(grid, np.linalg.inv(R)),
        Moves.BU: lambda grid: np.dot(grid, np.linalg.inv(U)),
        Moves.BB: lambda grid: np.dot(grid, np.linalg.inv(B)),
        Moves.BL: lambda grid: np.dot(grid, np.linalg.inv(L)),
        Moves.BD: lambda grid: np.dot(grid, np.linalg.inv(D)),
    }

    @staticmethod
    def invalid_move(self):
        print('Unknown move: ' + self.move)
        exit(0)

    def __init__(self, size):
        self.moves_to_print = []
        self.movelist = []
        self.size = size
        self.grid = []
        self.move = ''
        for c in colors:
            for x in range(size * size):
                self.grid.append(c)
        self.grid = np.array(self.grid)

    #   U
    # L F R B
    #   D

    visual = [
        [None, None, None,  9, 10, 11],
        [None, None, None, 14, 13, 12],
        [None, None, None, 15, 16, 17],
        [   0,    1,    2, 18, 19, 20, 36, 37, 38, 45, 46, 47],
        [   5,    4,    3, 23, 22, 21, 41, 40, 39, 50, 49, 48],
        [   6,    7,    8, 24, 25, 26, 42, 43, 44, 51, 52, 53],
        [None, None, None, 27, 28, 29],
        [None, None, None, 32, 31, 30],
        [None, None, None, 33, 34, 35]
    ]

    corners = [
        (18, 2, 15),
        (20, 17, 36),
        (26, 42, 29),
        (24, 27, 8),
        (45, 38, 11),
        (47, 9, 0),
        (53, 6, 33),
        (51, 35, 44),
    ]

    edges = {
        1: 14,
        3: 23,
        7: 32,
        5: 48,
        10: 46,
        12: 37,
        16: 19,
        14: 1,
        19: 16,
        21: 41,
        25: 28,
        23: 3,
        28: 25,
        30: 43,
        34: 52,
        32: 7,
        37: 12,
        39: 50,
        43: 30,
        41: 21,
        50: 39,
        46: 10,
        48: 5,
        52: 34
    }

    def print(self):
        for visual_schema_line in self.visual:
            line = ''
            for elem in visual_schema_line:
                if elem is None:
                    line += '  '
                else:
                    line += VisualFormatColors.get(self.grid[elem]) + '  '
            line += Back.RESET
            print(line)
        print()

    def do_move(self, move):
        self.move = move
        print(move)
        action = self.moves.get(move, self.invalid_move)
        self.grid = action(self.grid)
        self.print()

    def add_move(self, move):
        self.moves_to_print.append(move)
        self.movelist.append(move)

    def add_moves(self, moves):
        for move in moves:
            self.add_move(move)

    def do_moves(self):
        for move in self.movelist:
            self.do_move(move)
            self.print()
        self.movelist = []
