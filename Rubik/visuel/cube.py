from enum import Enum
import numpy as np
from OpenGL.GL import *


class Sides(Enum):
    F = 'RED'
    B = 'BLUE'
    U = 'WHITE'
    D = 'GREEN'
    L = 'ORANGE'
    R = 'YELLOW'


class Cuby:
    F = Sides.F
    B = Sides.B
    U = Sides.U
    D = Sides.D
    L = Sides.L
    R = Sides.R

    def draw(self, n, x, y, z):
        x *= 2
        y *= 2
        z *= 2

        p = [x - n, y - n, z - n]
        m = np.array([
            [0, 0, 0],
            [0, 0, 1],
            [0, 1, 0],
            [0, 1, 1],
        ])
        factor = [2, 0, 0]
        u = np.ones((4, 3), dtype=int)
        for i in range(3):
            m = np.roll(m, 1)
            factor = np.roll(factor, 1)
            list = np.add(np.multiply(p, u), m * 2)
            for l in list:
                glVertex3fv(l)
                glVertex3fv(np.add(l, factor))


def generateCube(size):
    mx = []
    for x in range(size):
        my = []
        for y in range(size):
            mz = []
            for z in range(size):
                mz.append(Cuby())
            my.append(mz)
        mx.append(my)
    return mx


class Cube:

    def __init__(self, size):
        self.size = size
        self.cubes = generateCube(size)

    def __str__(self):
        return 'size: ' + str(self.size) + '\ncubes: \n' + self.cubes.__str__()

    def draw(self):
        glBegin(GL_LINES)
        for x in range(self.size):
            for y in range(self.size):
                for z in range(self.size):
                    self.cubes[x][y][z].draw(self.size, x, y, z)
        glEnd()

