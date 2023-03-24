//-------------------------------------------------------
//
//  MyThing.h
//
//  VzlThing for a particle with gravity and friction
//
//  Copyright (c) 2019 Jerry Tessendorf
//
//
//--------------------------------------------------------


#include "Vector.h"
#include "Color.h"
#include "Box.h"
#include "VzlThing.h"



using namespace std;

namespace vzl{





class MyThing: public VzlThingyDingy
{
  public:

    // Feel free to customize the name of this thing.
    MyThing(const std::string nam = "Box");
   ~MyThing();

    //! Initialization, including GLUT initialization.
    //! Called once at the beginning.  Could be used
    //! to set up things once. s 
    //! It is optional to do anything with this.
    void Init( const std::vector<std::string>& args );
    
    // CALLBACK FUNCTIONS 
    //! Cascading callback for initiating a display event
    //! This is where you code the opengl calls to display 
    //! your system.
    void Display();

    //! Cascading callback keyboard events 
    //! This is called when you hit a key
    void Keyboard( unsigned char key, int x, int y );

    //! Cascading callback for usage information
    //! If you set up actions with the Keyboard()
    //! callback, you should include a statement 
    //! here as to what the keyboard option is.
    void Usage();

  private:

      Box box;
      bool show_all_sides;
      bool display_wire;
    
    //
    //
    //////////////////////////////////////////////// 

};


// This function constructs the MyThing and wraps it in a 
// smart pointer called a VzlThing. 
// There is nothing that you need to do with this.
vzl::VzlThing CreateMyThing();








}





