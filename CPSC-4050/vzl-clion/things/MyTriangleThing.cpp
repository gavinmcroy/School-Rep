//
// Created by Gavin Taylor Mcroy on 9/7/21.
//
#define GL_SILENCE_DEPRECATION

#if defined(__APPLE__)

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include "MyTriangleThing.h"
#include <cstdlib>
#include <iostream>
#include <omp.h>

using namespace std;

using namespace vzl;

MyTriangleThing::MyTriangleThing(const std::string &nam) :
        VzlThingyDingy(nam),
        triangle(Triangle(Vector(-1 * (1 + drand48()), -1 * (1 + drand48()), -1 * (1 + drand48())),
                          Vector(1 + drand48(), 1 + drand48(), 1 + drand48()))) {
    std::cout << name << " constructed\n";
}

MyTriangleThing::~MyTriangleThing() noexcept {
    std::cout << "Triangle death" << std::endl;
}

/* Do nothing */
void MyTriangleThing::Init(const std::vector<std::string> &args) {

}

/* Actually draw the triangle */
void MyTriangleThing::Display() {
    // Draw box as quads
    glBegin(GL_TRIANGLES);
    for (size_t i = 0; i < triangle.nb_walls(); i++) {
        const Color &ci = triangle.wall_color(i);
        glColor3f(ci.red(), ci.green(), ci.blue());
        const std::vector<Vector> &wall = triangle.triangle_wall(i);
        for (size_t p = 0; p < wall.size(); p++) {
            glVertex3f(wall[p].X(), wall[p].Y(), wall[p].Z());
        }
    }
    glEnd();
}

/* Do nothing */
void MyTriangleThing::Keyboard(unsigned char key, int x, int y) {

}

/* Do nothing */
void MyTriangleThing::Usage() {

}

vzl::VzlThing vzl::CreateMyThing() {
    return VzlThing(new MyTriangleThing());
}
