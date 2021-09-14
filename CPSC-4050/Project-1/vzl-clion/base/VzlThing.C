//-------------------------------------------------------
//
//  VzlThing.C
//
//  Generic container for things that work
//  in cooperation with the VzlViewer
//
//  Copyright (c) 2017 Jerry Tessendorf
//
//
//--------------------------------------------------------


#include "../include/VzlThing.h"
#include <iostream>
#include <sstream>


using namespace std;

using namespace vzl;


VzlThingyDingy::VzlThingyDingy(const std::string &nam) :
        viewer(0),
        visible(true),
        name(nam) {}


void VzlThingyDingy::Keyboard(unsigned char key, int x,
                              int y) { /* keyboard actions that are generic to all things could go here  */ }

void VzlThingyDingy::Idle() { /* idle actions that are generic to all things could go here  */ }

void VzlThingyDingy::Usage() {
    std::cout << "=== VzlThing ===\n";
    // Insert usage information here that is generic to all things
}

