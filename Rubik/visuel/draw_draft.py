# coding=utf-8
import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *
import numpy as np

def draw_cube(n, x, y, z):
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


def cubes(n):
    glBegin(GL_LINES)
    for x in range(n):
        for y in range(n):
            for z in range(n):
                draw_cube(n, x, y, z)
    glEnd()


def main():
    pygame.init()
    display = (800, 600)
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)

    gluPerspective(45, (display[0] / display[1]), 0.1, 50)


    glTranslatef(0.0,0.0, -10)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        glRotatef(1, 3, 1, 1)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        cubes(3)
        pygame.display.flip()
        pygame.time.wait(10)


main()
