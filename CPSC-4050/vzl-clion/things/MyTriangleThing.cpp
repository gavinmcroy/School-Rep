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
        VzlThingyDingy(nam) {
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
    /* Code that specifies triangle rules */
    int radian = 180;
    const std::vector<Vector> &wall = previous.triangleCords;
    Triangle triangle(wall[0], wall[1]);
    /* Here we check the normal vector angle to ensure less than 30 */
    /* arccos[(xa * xb + ya * yb + za * zb) / (√(xa2 + ya2 + za2) * √(xb2 + yb2 + zb2))] */
    double theta = acos(triangle.unitNormal() * previous.unitNormal() / (triangle.unitNormal().magnitude() *
                                                                         previous.unitNormal().magnitude()));
    theta = theta * (radian/M_PI);
    if(theta > MAX_ANGLE){
        std::cout<<"Problem found"<<std::endl;
        exit(1);
    }
    std::cout << "X Y Z PREVIOUS " << triangle.unitNormal().X() << " " << triangle.unitNormal().Y() << " "
              << triangle.unitNormal().Z() << std::endl;
    std::cout << "X Y Z PREVIOUS " << previous.unitNormal().X() << " " << previous.unitNormal().Y() << " "
              << previous.unitNormal().Z() << std::endl;
    std::cout << "Angle of norm " << theta << std::endl;
    return triangle;
}
