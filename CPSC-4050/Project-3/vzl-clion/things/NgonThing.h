//
// Created by Gavin Taylor Mcroy on 10/20/21.
//

#ifndef VZL_CLION_NGONTHING_H
#define VZL_CLION_NGONTHING_H

#include "../include/VzlThing.h"
#include "../include/Vector.h"
#include "../include/Color.h"
#include "Ngon.h"

using namespace vzl;

namespace vzl {

    class NgonThing : public VzlThingyDingy {
    public:
        NgonThing(int nbSides,
                  int nbNormals,
                  int nbTextureCoordinates,
                  const Vector &normal,
                  const Vector &center,
                  float radius);

        ~NgonThing() override;

        //! Initialization, including GLUT initialization.
        //! Called once at the beginning. Could be used//! //! to set up things once. s
        //! It is optional to do anything with this.
        void Init(const std::vector<std::string> &args);

        // CALLBACK FUNCTIONS
        //! Cascading callback for initiating a display event
        //! This is where you code the opengl calls to display
        //! your system.
        void Display();

        //! Cascading callback keyboard events
        //! This is called when you hit a key
        //!
        void Keyboard(unsigned char key, int x, int y);

        //! Cascading callback for usage information
        //! If you set up actions with the Keyboard()
        //! callback, you should include a statement
        //! here as to what the keyboard option is.
        void Usage();

    private:
        bool display_wire;
        Ngon polygon;

        void generate_symmetric_ngon(int nb_sides,
                                     int nb_normals,
                                     int nb_texture_coordinates,
                                     const Vector &normal,
                                     const Vector &center,
                                     float radius);

        static Color generate_vertex_color(const Vector &tc) ;
    };

    /* This function constructs the NgonThing and wraps it in a
     * smart pointer called a VzlThing.
     * Note that the signature of this function is the same as for the NgonThing constructor,
     * and for the generate_symmetric_ngon private method in NgonThing */
    vzl::VzlThing CreateNgonThing(int nb_sides,
                                  int nb_normals,
                                  int nb_texture_coordinates,
                                  const Vector &normal,
                                  const Vector &center,
                                  float radius);
}

#endif //VZL_CLION_NGONTHING_H
