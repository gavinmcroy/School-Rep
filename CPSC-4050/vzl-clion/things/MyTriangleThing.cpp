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

using namespace std;

using namespace vzl;

MyTriangleThing::MyTriangleThing(const std::string &nam) :
        VzlThingyDingy(nam) {
    /* if no triangle, setup default, else build triangle based on previous */
    for (int i = 0; i < MAX_TRIANGLES; i++) {
        if (i == 0) {
            triangles.emplace_back();
        } else {
            triangles.push_back(generationRules(triangles[i - 1]));
        }
    }
    std::cout << MAX_TRIANGLES << " " << name << " constructed\n";
}

MyTriangleThing::~MyTriangleThing() noexcept {
    std::cout << "Triangle death" << std::endl;
}

/* Do nothing */
void MyTriangleThing::Init(const std::vector<std::string> &args) {

}

/* Actually draw the triangle */
void MyTriangleThing::Display() {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < triangles.size(); i++) {
        /* Drawing stuff */
        const Color &ci = triangles[i].wall_color(0);
        glColor3f(ci.red(), ci.green(), ci.blue());
        const std::vector<Vector> &wall = triangles[i].triangleCords;

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

/* Give me the previous triangle, and ill generate one that meets the requirement */
Triangle MyTriangleThing::generationRules(const Triangle &previous) {
    int radian = 180;
    const std::vector<Vector> &vertices = previous.triangleCords;
    /* 0 = v1, 1 = v2 */
    int x = (int) (drand48() * 3);
    int y = (int) (drand48() * 3);
    while (y == x) {
        y = (int) (drand48() * 3);
    }
    std::cout << "X " << x << std::endl;
    Triangle triangle(vertices[x], vertices[y]);


    /* arccos[(xa * xb + ya * yb + za * zb) / (√(xa2 + ya2 + za2) * √(xb2 + yb2 + zb2))] */
    double theta = acos(triangle.unitNormal() * previous.unitNormal() / (triangle.unitNormal().magnitude() *
                                                                         previous.unitNormal().magnitude()));
    theta = theta * (radian / M_PI);
    /* angle each of the triangles normal vec must be less than MAX_ANGLE */
    while (theta > MAX_ANGLE) {
        x = (int) (drand48() * 3);
        y = (int) (drand48() * 3);
        while (y == x) {
            y = (int) (drand48() * 3);
        }
        Triangle temp(vertices[x], vertices[y]);
        theta = acos(temp.unitNormal() * previous.unitNormal() / (temp.unitNormal().magnitude() *
                                                                  previous.unitNormal().magnitude()));
        theta = theta * (radian / M_PI);
    }
    std::cout << "Angle of norm " << theta << std::endl;
    return triangle;
}
