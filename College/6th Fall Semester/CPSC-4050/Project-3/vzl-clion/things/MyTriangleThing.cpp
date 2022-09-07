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
    for (auto & triangle : triangles) {
        /* Drawing stuff */
        const Color &ci = triangle.wall_color(0);
        glColor3f(ci.red(), ci.green(), ci.blue());
        const std::vector<Vector> &cords = triangle.triangleCords;

        for (const auto & cord : cords) {
            glVertex3f(cord.X(), cord.Y(), cord.Z());
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
Triangle MyTriangleThing::generationRules(const Triangle &previous) const {
    int radian = 180;
    unsigned int numVertices = previous.triangleCords.size();
    const std::vector<Vector> &vertices = previous.triangleCords;

    /* Randomly pick 2 vertices from the last triangle */
    int x = (int) (drand48() * numVertices);
    int y = (int) (drand48() * numVertices);
    /* if you pick 2 of the same vertices trouble occurs */
    while (y == x) {
        y = (int) (drand48() * numVertices);
    }
    Triangle triangle(vertices[x], vertices[y]);

    /* Dandy formula -> arccos[(xa * xb + ya * yb + za * zb) / (√(xa2 + ya2 + za2) * √(xb2 + yb2 + zb2))] */
    double theta = acos(triangle.unitNormal() * previous.unitNormal() / (triangle.unitNormal().magnitude() *
            previous.unitNormal().magnitude()));
    theta = theta * (radian / M_PI);

    /* The angle of each of the triangles getNormal vec must be less than MAX_ANGLE else, randomly generate
     * until triangle satisfies requirements */
    while (theta > MAX_ANGLE) {
        /* Randomly pick 2 vertices from the last triangle */
        x = (int) (drand48() * numVertices);
        y = (int) (drand48() * numVertices);
        /* if you pick the same vertices trouble occurs */
        while (y == x) {
            y = (int) (drand48() * numVertices);
        }
        Triangle temp = Triangle(vertices[x], vertices[y]);
        theta = acos(temp.unitNormal() * previous.unitNormal() / (temp.unitNormal().magnitude() *
                previous.unitNormal().magnitude()));
        theta = theta * (radian / M_PI);

        /* Our triangle has been found */
        if(theta < MAX_ANGLE){
            return temp;
        }
    }
    return triangle;
}
