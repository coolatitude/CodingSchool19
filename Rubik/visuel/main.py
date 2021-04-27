# coding=utf-8
from cube import Cube
import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *



def main():
    c = Cube(4)
    pygame.init()
    display = (1600, 1200)
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
        c.draw()
        pygame.display.flip()
        pygame.time.wait(10)


main()

main()
