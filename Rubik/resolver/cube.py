from enum import Enum
import numpy as np
from moves import F, R, U, B, L, D, Right, Down, DownSide

from colorama import Back

import config


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


class Faces:
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
        Moves.F2: lambda grid: np.dot(np.dot(grid, F), F),
        Moves.R2: lambda grid: np.dot(np.dot(grid, R), R),
        Moves.U2: lambda grid: np.dot(np.dot(grid, U), U),
        Moves.B2: lambda grid: np.dot(np.dot(grid, B), B),
        Moves.L2: lambda grid: np.dot(np.dot(grid, L), L),
        Moves.D2: lambda grid: np.dot(np.dot(grid, D), D),
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

    corners_expanded = {
        18: (2,  15),
        2:  (15, 18),
        15: (18, 2),
        20: (17, 36),
        17: (36, 20),
        36: (20, 17),
        26: (42, 29),
        42: (29, 26),
        29: (26, 42),
        24: (27, 8),
        27: (8,  24),
        8:  (24, 27),
        45: (38, 11),
        38: (11, 45),
        11: (45, 38),
        47: (9,  0),
        9:  (0,  47),
        0:  (47, 9),
        53: (6,  33),
        6:  (33, 53),
        33: (53, 6),
        51: (35, 44),
        35: (44, 51),
        44: (51, 35)
    }

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

    def print_moves(self):
        print(*self.moves_to_print, sep=' ')

    def do_move(self, move):
        self.move = move
        action = self.moves.get(move, self.invalid_move)
        self.grid = action(self.grid)
        if config.verbose:
            self.print()

    def add_move(self, move):
        self.moves_to_print.append(move)
        self.do_move(move)

    def add_moves(self, moves):
        for move in moves:
            self.add_move(move)

    def clean_moves(self):
        changes = 1

        combinations = {
            Moves.F: Moves.BF,
            Moves.R: Moves.BR,
            Moves.U: Moves.BU,
            Moves.B: Moves.BB,
            Moves.L: Moves.BL,
            Moves.D: Moves.BD,
            Moves.BF: Moves.B,
            Moves.BR: Moves.B,
            Moves.BU: Moves.B,
            Moves.BB: Moves.B,
            Moves.BL: Moves.B,
            Moves.BD: Moves.B,
        }

        replacements = {
            Moves.F2: Moves.F,
            Moves.R2: Moves.R,
            Moves.U2: Moves.U,
            Moves.B2: Moves.B,
            Moves.L2: Moves.L,
            Moves.D2: Moves.D,
        }

        for move in [Moves.F2, Moves.R2, Moves.U2, Moves.B2, Moves.L2, Moves.D2]:
            while move in self.moves_to_print:
                ind = self.moves_to_print.index(move)
                self.moves_to_print.remove(move)
                self.moves_to_print.insert(ind, replacements[move])
                self.moves_to_print.insert(ind, replacements[move])

        changes = 1
        while changes > 0:
            i = 0
            changes = 0
            while i < len(self.moves_to_print) - 1:
                if self.moves_to_print[i + 1] == combinations[self.moves_to_print[i]]:
                    self.moves_to_print.pop(i)
                    self.moves_to_print.pop(i)
                    changes += 1
                else:
                    i += 1
        changes = 1
        while changes > 0:
            i = 0
            changes = 0
            while i < len(self.moves_to_print) - 2:
                if self.moves_to_print[i] == self.moves_to_print[i + 1] and self.moves_to_print[i] == self.moves_to_print[i + 2]:
                    self.moves_to_print.insert(i, combinations[self.moves_to_print[i]])
                    self.moves_to_print.pop(i + 1)
                    self.moves_to_print.pop(i + 1)
                    self.moves_to_print.pop(i + 1)
                    changes += 1
                else:
                    i += 1