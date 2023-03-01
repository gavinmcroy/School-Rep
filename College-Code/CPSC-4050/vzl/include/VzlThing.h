//-------------------------------------------------------
//
//  VzlThing.h
//
//  Generic container for things that work
//  in cooperation with the VzlViewer
//  This is a base class that does nothing.
//
//  Copyright (c) 2017,2021 Jerry Tessendorf
//
//
//--------------------------------------------------------


#ifndef ____VZL_THING_H____
#define ____VZL_THING_H____

#include <string>
#include <vector>
#include <memory>
#include <map>


using namespace std;

namespace vzl{

class VzlViewer;

class VzlThingyDingy
{
  public:

    VzlThingyDingy( const std::string& nam = "VzlThingyDingyNoName" );
    virtual ~VzlThingyDingy() {};

    //! Initialization, including GLUT initialization.
    virtual void Init( const std::vector<std::string>& args ) {};
   
    //
    //  Graphics interface
    //
 
    // Callback functions
    //! Cascading callback for initiating a display event
    virtual void Display() {};
    //! Cascading callback for a keyboard event 
    virtual void Keyboard( unsigned char key, int x, int y );
    //! Cascading callback for a mouse event 
    virtual void Mouse( int button, int state, int x, int y ){};
    //! Cascading callback for a mouse motion event 
    virtual void Motion( int x, int y ){};
    //! Cascading callback for a GLUT Special event 
    virtual void Special( int key, int x, int y ){};
    //! Cascading callback for an idle  event 
    virtual void Idle();
    //! Cascading callback for a window reshape 
    virtual void Reshape( int w, int h ){};
    //! Cascading callback to home parameters
    virtual void Home(){};
    //! Cascading callback for usage information
    virtual void Usage();

    //! Provides the name assigned to the thingy dingy
    const std::string& Name() const { return name; }

    bool isVisible() const { return visible; }
    void setInvisible() { visible = false; }
    void setVisible() { visible = true; }
    void toggleVisible() { visible = !visible; }

    VzlViewer* viewer;

  protected:

    bool visible;
    const std::string name;

  private: 

    VzlThingyDingy(){};
};



typedef std::shared_ptr<VzlThingyDingy> VzlThing;




}





#endif
