//
// Created by Gavin Taylor Mcroy on 9/7/21.
//

#ifndef VZL_CLION_MYTRIANGLETHING_H
#define VZL_CLION_MYTRIANGLETHING_H

#include "../include/Vector.h"
#include "../include/Color.h"
#include "Triangle.h"
#include "../include/VzlThing.h"

namespace vzl {

    class MyTriangleThing : public VzlThingyDingy {
    public:

        // Feel free to customize the name of this thing.
        explicit MyTriangleThing(const std::string &nam = "Triangle");

        ~MyTriangleThing() override;

        //! Initialization, including GLUT initialization.
        //! Called once at the beginning.  Could be used
        //! to set up things once. s
        //! It is optional to do anything with this.
        void Init(const std::vector<std::string> &args) override;

        // CALLBACK FUNCTIONS
        //! Cascading callback for initiating a display event
        //! This is where you code the opengl calls to display
        //! your system.
        void Display() override;

        //! Cascading callback keyboard events
        //! This is called when you hit a key
        void Keyboard(unsigned char key, int x, int y) override;

        //! Cascading callback for usage information
        //! If you set up actions with the Keyboard()
        //! callback, you should include a statement
        //! here as to what the keyboard option is.
        void Usage() override;

    private:
        const int MAX_TRIANGLES = 1000;

        const int MAX_ANGLE = 30;

        std::vector<Triangle> triangles;

        Triangle generationRules(const Triangle& previous);

    };

// This function constructs the MyThing and wraps it in a
// smart pointer called a VzlThing.
// There is nothing that you need to do with this.
    vzl::VzlThing CreateMyThing();

}
#endif //VZL_CLION_MYTRIANGLETHING_H
