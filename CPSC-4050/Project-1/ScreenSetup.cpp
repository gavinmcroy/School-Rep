//
// Created by Gavin Taylor Mcroy on 9/1/21.
//
#define GL_SILENCE_DEPRECATION

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "ScreenSetup.h"

void ScreenSetup::openGLSetup(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Top notch window");
    glutDisplayFunc(mainDisplay);
    glutMainLoop();
}

/* TODO Implement */
void ScreenSetup::triangleGenerator() {
    /* Triangle must be a random RGB Color. Must be 30 triangles */
}

void mainDisplay() {
    glClearColor(255.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
