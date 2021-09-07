

#include "../include/VzlViewer.h"
#include "MyTriangleThing.h"


int main(int argc, char **argv) {
    // Set up command line arguments, if any
    std::vector<std::string> args;
    for (int i = 0; i < argc; i++) {
        args.push_back(argv[i]);
    }


    // Instantiate a viewer
    vzl::VzlViewer *viewer = vzl::CreateViewer();

    // Set up a thing
    //for(int i = 0; i < 5; i++) {
    vzl::VzlThing mything = vzl::CreateMyThing();
    viewer->AddThing(mything);
    //}


    // Initialize viewer
    viewer->Init(args);
    // Run the (GLUT) main loop
    viewer->MainLoop();

}
