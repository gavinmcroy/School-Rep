//
// Created by Gavin Taylor Mcroy on 10/20/21.
//
#define GL_SILENCE_DEPRECATION

#include <iostream>
#include "NgonThing.h"
#include "GLUT/glut.h"
#include "OpenGL/gl.h"

NgonThing::NgonThing(int nb_sides, int nb_normals, int nb_texture_coordinates, const Vector &normal,
                     const Vector &center, const float radius) : VzlThingyDingy("NgonThing"),
                                                                 display_wire(false), polygon() {
    std::cout << "NgonThing constructor created " << std::endl;
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
    double paddingAmount = -.01;
    switch (key) {
        case 'd': {
//            std::cout << "D key pressed" << std::endl;
            for (int i = 0; i < polygon.getNgonSize()+1; i++) {
                if(i==0){
                    continue;
                }
                Vector vert, b, c;
                polygon.faceValues(i, vert, b, c);
//                int rand = drand48() * 3;
//                if (rand == 0) {
//                    vert.set(vert.X() + paddingAmount, vert.Y(), vert.Z());
//                } else if (rand == 1) {
//                    vert.set(vert.X(), vert.Y() + paddingAmount, vert.Z());
//                } else {
//                    vert.set(vert.X(), vert.Y(), vert.Z() + paddingAmount);
//                }
//
//                polygon.setFaceValues(i, vert, b, c);
                vert = vert + (paddingAmount * b);
                polygon.setFaceValues(i, vert, b, c);
            }
        }
    }
}

void NgonThing::Usage() {
    VzlThingyDingy::Usage();
}

void NgonThing::generate_symmetric_ngon(int nb_sides, int nb_normals, int nb_texture_coordinates, const Vector &normal,
                                        const Vector &center, const float radius) {
    /* Handles data structure generation */
    /* I'm pretty sure I can get away with using the radius as a point, then a straight line to another point of
     * distance radius, then using the circumference, estimate the vector distance in a straight line to the next triangle
     * point that is also radius distance */

    /* Temporary test values to ensure triangle display works */
    std::vector<Vector> allVertices, allNorm(3), allST(3);
    std::vector<Face> face;

    std::cout << "Generating symmetric polygon" << std::endl;
    /* every single face shares a center location. One triangle must share a point. Therefore, only one
     * allVertices must be generated on each loop iteration */

    /* Generates all vertices */
    for (int i = 0; i < nb_sides; i++) {
        float x = center.X() + radius * sin(2.0 * M_PI * i / nb_sides);
        float y = center.Y() + radius * cos(2.0 * M_PI * i / nb_sides);
        allVertices.emplace_back(x, y, center.Z());

    }

    /* Generates all texture coord and assigns randomly to sides */
    for (int i = 0; i < nb_sides; i++) {
        double s = drand48();
        double t = drand48();
        allST.emplace_back(s, t, 0);
    }

    /* TODO Generates all normals and assigns randomly to sides. Its best to generate the same amount of
     * normals as sides. */
    for (int i = 0; i < nb_sides; i++) {
        Vector random = Vector(drand48(), drand48(), drand48());
        random.normalize();
        allNorm.push_back(random);
    }

    /* Generation of actual polygon object */
    polygon = Ngon(allVertices, allNorm, allST, face);
    std::cout << polygon.getNgonSize();

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
