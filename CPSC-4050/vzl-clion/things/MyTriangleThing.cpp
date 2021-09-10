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
    int numVertices = previous.triangleCords.size();
    const std::vector<Vector> &vertices = previous.triangleCords;
    /* 0 = v1, 1 = v2 */

    /* Randomly pick 2 vertices from the last triangle */
    int x = (int) (drand48() * numVertices);
    int y = (int) (drand48() * numVertices);
    /* if you pick the same vertices trouble occurs */
    while (y == x) {
        y = (int) (drand48() * numVertices);
    }
    Triangle triangle(vertices[x], vertices[y]);

    /* arccos[(xa * xb + ya * yb + za * zb) / (√(xa2 + ya2 + za2) * √(xb2 + yb2 + zb2))] */
    double theta = acos(triangle.unitNormal() * previous.unitNormal() / (triangle.unitNormal().magnitude() *
            previous.unitNormal().magnitude()));
    theta = theta * (radian / M_PI);

    /* angle each of the triangles normal vec must be less than MAX_ANGLE else, new triangle */
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
        if(theta < MAX_ANGLE){
            return temp;
        }
    }
    return triangle;
}
