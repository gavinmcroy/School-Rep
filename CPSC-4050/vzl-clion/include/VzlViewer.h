//-------------------------------------------------------
//
//  VzlViewer.h
//
//  This viewer is a wrapper of the Glut calls needed to
//  display opengl data.  Options for zooming, etc are 
//  available for derived classes to use.
//
//  There is a notion of VzlThings, which are abstract
//  entities that can do processing and handle glut-like
//  calls for Idle, Init, Display, and other API options.
//  
//
//  Copyright (c) 2003,2017,2021 Jerry Tessendorf
//
//
//--------------------------------------------------------


#ifndef ____VZL_VIEWER_H____
#define ____VZL_VIEWER_H____

#include <cstring>
#include <vector>
#include "VzlThing.h"

using namespace std;

namespace vzl{


class VzlViewer
{
  public:

    //! The viewer is a singleton
    static  VzlViewer* Instance()
    {
       if(pVzlViewer==nullptr)
       {
          pVzlViewer = new VzlViewer();
       }
       return pVzlViewer;
    }

    ~VzlViewer();

    //! Returns reference to list of objects in scene
    const std::vector<vzl::VzlThing> &objectsInScene();

    //! Initialization, including GLUT initialization.
    void Init( const std::vector<std::string>& args );
    //! Invokes the GLUT main loop.
    void MainLoop();
    
    //! Set the window width
    void SetWidth( const int w ) { width = w; }
    //! Set the window height 
    void SetHeight( const int h ) { height = h; }

    //! Get the window width
    const int& GetWidth() { return width;  }
    //! Get the window height 
    const int& GetHeight() { return height; }

    //! Set the window title
    void SetTitle( const std::string& t ){ title = t; }
    //! Set the window title
    void SetTitle( const char * t ) { title = t; }
    //! Get the window title
    const std::string& GetTitle() { return title; }

    // Callback functions
    //! Cascading callback for initiating a display event
    void Display();
    //! Cascading callback for a keyboard event 
    void Keyboard( unsigned char key, int x, int y );
    //! Cascading callback for a mouse event 
    void Mouse( int button, int state, int x, int y );
    //! Cascading callback for a mouse motion event 
    void Motion( int x, int y );
    //! Cascading callback for a GLUT Special event 
    void Special( int key, int x, int y ){}
    //! Cascading callback for an idle  event 
    void Idle();
    //! Cascading callback for a window reshape 
    void Reshape( int w, int h );
    //! Cascading callback for reseting parameters
    void Reset();
    //! Cascading callback to home parameters
    void Home();

    //! Add a thing to the collection that are updated during each idle period.
    void AddThing( vzl::VzlThing& t );

    //! Cascading callback for usage information
    void Usage();

    //! Set the camera for 3D viewing.
    void SetCameraEyeViewUp( float eyex, float eyey, float eyez, float viewx, float viewy, float viewz, float upx, float upy, float upz ); 

  private:

    bool initialized;
    int width, height;
    unsigned int display_mode;

    std::string title;
    int mouse_x, mouse_y;
    int keystate, button;
    int mouse_state;
    float current_raster_pos[4];
   
    float camera_fov;
    float camera_aspect;
    float camera_near;
    float camera_far;
    float camera_eye_x, camera_eye_y, camera_eye_z;
    float camera_view_x, camera_view_y, camera_view_z;
    float camera_up_x, camera_up_y, camera_up_z;
    float camera_right_x, camera_right_y, camera_right_z;

    void ComputeEyeUpRight(int dx, int dy);
    void ComputeEyeShift(float dz);

    // These are the objects that do the important processing. 
    std::vector<vzl::VzlThing> things;

    static VzlViewer* pVzlViewer;

    // dont allow any of these
    VzlViewer();
    VzlViewer( const VzlViewer& );
    VzlViewer& operator= (const VzlViewer&);

};


VzlViewer* CreateViewer();



}





#endif
