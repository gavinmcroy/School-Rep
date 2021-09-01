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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Top notch window");
    glutDisplayFunc(mainDisplay);
    glutMainLoop();
}

/* TODO Implement */
void ScreenSetup::triangleGenerator() {
    glBegin(GL_TRIANGLES);
    glVertex3f(0.4, 0.5,1.0);
    glVertex3f(0.6, 0.6,1.0);
    glVertex3f(0.6, 0.4,1.0);
    glEnd();
}

void mainDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(1.0,0,0);
    ScreenSetup::triangleGenerator();
    glutSwapBuffers();
}
