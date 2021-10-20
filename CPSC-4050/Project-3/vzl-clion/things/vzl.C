

#include "../include/VzlViewer.h"
#include "../include/Vector.h"
#include "MyTriangleThing.h"

using namespace vzl;

int main(int argc, char **argv) {
    // Set up command line arguments, if any
    std::vector<std::string> args;
    for (int i = 0; i < argc; i++) {
        args.emplace_back(argv[i]);
    }


    // Instantiate a viewer
    vzl::VzlViewer *viewer = vzl::CreateViewer();

    int nGonSides = 5;
    int nGonNormals = 4;
    int nGoneTextCord = 10;
    Vector nGonCenter(0,0,0);
    Vector nGonNormal(0,1,1);
    float nGoneRadius = 4.5f;


    //vzl::VzlThing myThing = vzl::CreateMyNgonThing();
    vzl::VzlThing myThing = vzl::CreateMyThing();
    viewer->AddThing(myThing);;



    // Initialize viewer
    viewer->Init(args);
    // Run the (GLUT) main loop
    viewer->MainLoop();

}
