//
// Created by Gavin Taylor Mcroy on 10/20/21.
//
#define GL_SILENCE_DEPRECATION

#include <iostream>
#include "NgonThing.h"
#include "GLUT/glut.h"
#include "OpenGL/gl.h"

NgonThing::NgonThing(int nb_sides, int nb_normals, int nb_texture_coordinates, const Vector &normal,
                     const Vector &center,
                     const float radius) :
        VzlThingyDingy("NgonThing"),
        display_wire(false) {
    generate_symmetric_ngon(nb_sides, nb_normals, nb_texture_coordinates, normal, center, radius);
}

NgonThing::~NgonThing() {
    std::cout << "Destroyed nGon" << std::endl;
}

void NgonThing::Init(const vector<std::string> &args) {

}


void NgonThing::Display() {
    if (display_wire) {
        // Draw polygon as wireframe
        glBegin(GL_LINE_LOOP);
        for (size_t i = 0;
             i < polygon.getNgonSize(); i++) {// Get the postion, getNormal, texture coordinates of a getVertex
            Vector X, N, st;
            polygon.faceValues(i, X, N, st);
            // Extract the texture coordinates and do some math
            // This math is used to select a color for the getVertex
            Color ci = generate_vertex_color(st);
            // Tell OpenGL about the color and position of the getVertex
            glColor3f(ci.red(), ci.green(), ci.blue());
            glVertex3f(X.X(), X.Y(), X.Z());
        }
        glEnd();
    } else {
        // Solid polygon
        glBegin(GL_POLYGON);
        for (size_t i = 0; i < polygon.getNgonSize(); i++) {
            // Get the postion, getNormal, texture coordinates of a getVertex
            Vector X, N, st;
            polygon.faceValues(i, X, N, st);
            // Extract the texture coordinates and do some math
            // This math is used to select a color for the getVertex
            Color ci = generate_vertex_color(st);
            // Tell OpenGL about the color and position of the getVertex
            glColor3f(ci.red(), ci.green(), ci.blue());
            glVertex3f(X.X(), X.Y(), X.Z());
        }
        glEnd();
    }
}

void NgonThing::Keyboard(unsigned char key, int x, int y) {
    /* TODO empty implementation */
}

void NgonThing::Usage() {
    VzlThingyDingy::Usage();
}

void NgonThing::generate_symmetric_ngon(int nb_sides, int nb_normals, int nb_texture_coordinates, const Vector &normal,
                                        const Vector &center, const float radius) {
    /* TODO Handle data structure generation */
    polygon = Ngon();

}

Color NgonThing::generate_vertex_color(const Vector &st) {
    double ss = st.X() * st.X();
    double tt = st.Y() * st.Y();
    double smt = (st.X() - st.Y()) * (st.X() - st.Y());
    double denom = 3.0 / (ss + tt + smt + 0.00001);
    return Color(ss * denom, tt * denom, smt * denom, 0);
}

vzl::VzlThing vzl::CreateNgonThing(int nb_sides, int nb_normals, int nb_texture_coordinates, const Vector &normal,
                                   const Vector &center, float radius) {
    return VzlThing(new NgonThing(nb_sides, nb_normals, nb_texture_coordinates, normal, center, radius));
}
