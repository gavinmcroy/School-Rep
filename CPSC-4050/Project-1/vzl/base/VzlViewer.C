//-------------------------------------------------------
//
//  VzlViewer.C
//
//  This viewer is a wrapper of the Glut calls needed to
//  display opengl data.  Options for zooming, etc,
//  are available for derived classes to use.
//
//  There is a notion of VzlThings, which are abstract
//  entities that can do processing and handle glut-like
//  calls for Idle, Init, Display, and other API options.
 
//
//  Copyright (c) 2003,2017,2021 Jerry Tessendorf
//
//--------------------------------------------------------

//#include <GL/glut.h>



#ifdef __APPLE__
  #include <OpenGL/gl.h>   // OpenGL itself.
  #include <OpenGL/glu.h>  // GLU support library.
  #include <GLUT/glut.h>
#else
  #include <GL/gl.h>   // OpenGL itself.
  #include <GL/glu.h>  // GLU support library.
  #include <GL/glut.h> // GLUT support library.
#endif




#include <iostream>
#include <sstream>
#include <cmath>
#include "VzlViewer.h"
#include <omp.h>


using namespace std;
namespace vzl{

//////////////////////////////////////////////////////////////////////////////////
// These are the GLUT Callbacks that are implemented in VzlViewer and VzlThings.
void cbDisplayFunc()
{
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );	
   VzlViewer::Instance() -> Display();
   glutSwapBuffers();
   glutPostRedisplay();
}

void cbIdleFunc()
{
   VzlViewer::Instance() -> Idle();
}


void cbKeyboardFunc( unsigned char key, int x, int y )
{
   VzlViewer::Instance() -> Keyboard( key, x, y );
}

void cbMotionFunc( int x, int y )
{
   
   VzlViewer::Instance() -> Motion( x, y );
   glutPostRedisplay();
}

void cbMouseFunc( int button, int state, int x, int y )
{
   VzlViewer::Instance() -> Mouse( button, state, x, y );
}

void cbReshapeFunc( int w, int h )
{
   VzlViewer::Instance() -> Reshape( w, h );
   glutPostRedisplay();
}
//////////////////////////////////////////////////////////////////////////////////


VzlViewer* VzlViewer::pVzlViewer = nullptr;
	
VzlViewer::VzlViewer() : 
   initialized    ( false ),
   width          ( 1024 ), 
   height         ( 1024 ),
   display_mode   ( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH ),
   title          ( string("VZL Viewer") ),
   mouse_x        ( 0 ),
   mouse_y        ( 0 ),
   camera_fov     (35.0),
   camera_aspect  (1.0),
   camera_near    (0.01),
   camera_far     (100000.0),
   camera_eye_x   (0.0),
   camera_eye_y   (0.0),
   camera_eye_z   (-15.0),
   camera_view_x  (0.0),
   camera_view_y  (0.0),
   camera_view_z  (0.0),
   camera_up_x    (0.0),
   camera_up_y    (1.0),
   camera_up_z    (0.0),
   camera_right_x (1.0),
   camera_right_y (0.0),
   camera_right_z (0.0)
{
   omp_set_num_threads(omp_get_max_threads());
   cout << "VzlViewer Loaded\n";
}

VzlViewer::~VzlViewer(){}

void VzlViewer::Init( const std::vector<std::string>& args )
{
   int argc = (int)args.size();
   char** argv = new char*[argc];
   for( int i=0;i<argc;i++)
   {
      argv[i] = new char[args[i].length() + 1];
      std::strcpy(argv[i], args[i].c_str());
   }

   string window_title = title;
   if( !things.empty() )
   {
      window_title = "";
      for( size_t i=0;i<things.size();i++)
      {
         window_title = window_title + things[i]->Name() + " + ";
      }

   }


   glutInit( &argc, argv );
   glutInitDisplayMode( display_mode );
   glutInitWindowSize( width, height );
   glutCreateWindow( window_title.c_str() );
   glClearColor(0.5,0.5,0.6,0.0);

   camera_aspect = (float)width/(float)height;

   glutDisplayFunc( &cbDisplayFunc );
   glutIdleFunc( &cbIdleFunc );
   glutKeyboardFunc( &cbKeyboardFunc );
   glutMotionFunc( &cbMotionFunc );
   glutMouseFunc( &cbMouseFunc );
   glutReshapeFunc( &cbReshapeFunc );

   for( size_t i=0;i<things.size();i++)
   {
      things[i]->Init(args);
   }
   initialized = true;
   cout << "VzlViewer Initialized\n";
}

void VzlViewer::MainLoop()
{
   Usage();
   glutMainLoop();
}


void VzlViewer::Display()
{
   glLoadIdentity();
   gluPerspective( camera_fov, camera_aspect, camera_near, camera_far );
   gluLookAt( camera_eye_x, camera_eye_y, camera_eye_z,    // Camera eye point
               camera_view_x, camera_view_y, camera_view_z, // Camera view point
               camera_up_x, camera_up_y, camera_up_z        // Camera up direction
             );

   glEnable(GL_DEPTH_TEST);
   glDepthRange( camera_near, camera_far );

   for( size_t i=0;i<things.size();i++)
   {
      if( things[i]->isVisible() ) { things[i]->Display(); }
   }
}



void VzlViewer::Reshape( int w, int h )
{
   width = w;
   height = h;
   camera_aspect = (float)width/(float)height;

   glViewport( 0, 0, (GLsizei) width, (GLsizei) height );
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();

   for( size_t i=0;i<things.size();i++)
   {
      things[i]->Reshape(w,h);
   }
}

void VzlViewer::Keyboard( unsigned char key, int x, int y )
{
   switch (key)
   {
      case 'f':
         camera_fov /= 1.01;
	 std::cout << "FOV " << camera_fov << std::endl;
         break;
      case 'F':
         camera_fov *= 1.01;
         if( camera_fov > 170.0){ camera_fov = 170.0; }
	 std::cout << "FOV " << camera_fov << std::endl;
	 break;
      case '+':
      case '=':
         ComputeEyeShift(0.7);
	 std::cout << "Eye " << camera_eye_x << " " << camera_eye_y << " " << camera_eye_z << std::endl;
         break;
      case '-':
      case '_':
         ComputeEyeShift(-0.7);
	 std::cout << "Eye " << camera_eye_x << " " << camera_eye_y << " " << camera_eye_z << std::endl;
         break;
      case 'h':
	     Home();
      break;
      case 'u':
	     Usage();
      break;
   }

   for( size_t i=0;i<things.size();i++)
   {
      things[i]->Keyboard(key,x,y);
   }
}


void VzlViewer::Motion( int x, int y )
{
   float dx = x - mouse_x;
   float dy = y - mouse_y;
   float pos_x = current_raster_pos[0] + dx;
   float pos_y = current_raster_pos[1] - dy;
   glRasterPos2f( pos_x, pos_y ); 

   // camera motion perp to view direction
   if(keystate == GLUT_ACTIVE_SHIFT )
   {
     ComputeEyeUpRight(dx,dy);
   }
   //else if (keystate == GLUT_ACTIVE_CTRL)
   //{
   //}
   //else if (keystate == GLUT_ACTIVE_ALT)
   //{
   //}

   for( size_t i=0;i<things.size();i++)
   {
      things[i]->Motion(x,y);
   }
   mouse_x = x;
   mouse_y = y;
}


void VzlViewer::Mouse( int b, int state, int x, int y )
{
   mouse_x = x;
   mouse_y = y;
   keystate = glutGetModifiers();
   button = b;
   mouse_state = state;
   glGetFloatv( GL_CURRENT_RASTER_POSITION, current_raster_pos );

   for( size_t i=0;i<things.size();i++)
   {
      things[i]->Mouse(b,state,x,y);
   }
}


void VzlViewer::Idle()
{
   for( size_t i=0;i<things.size();i++)
   {
      things[i]->Idle();
   }
}


void VzlViewer::Usage()
{
   cout << "VZL Viewer   usage:\n";
   cout << "f/F          reduce/increase the camera FOV\n";
   cout << "+/=          move camera farther from the view point\n";
   cout << "-/_          move camera closer to the view point\n";
   cout << "SHIFT+mouse  move camera perpendicular to the view direction\n";
   cout << "h            home display parameters\n";
   cout << "u            display this usage message\n";
 
   for( size_t i=0;i<things.size();i++)
   {
      things[i]->Usage();
   }
}


void VzlViewer::Home()
{
   std::cout << "Home\n";
   camera_fov     = 35.0;
   camera_near    = 0.01;
   camera_far     = 100.0;
   camera_eye_x   = 0.0;
   camera_eye_y   = 0.0;
   camera_eye_z   = -15.0;
   camera_view_x  = 0.0;
   camera_view_y  = 0.0;
   camera_view_z  = 0.0;
   camera_up_x    = 0.0;
   camera_up_y    = 1.0;
   camera_up_z    = 0.0;
   camera_right_x = 1.0;
   camera_right_y = 0.0;
   camera_right_z = 0.0;
 
   for( size_t i=0;i<things.size();i++)
   {
      things[i]->Home();
   }
}



void VzlViewer::ComputeEyeUpRight(int dx, int dy)
{

// dx --> rotation around y axis
// dy --> rotation about camera right axis


   float vvx = camera_eye_x-camera_view_x; 
   float vvy = camera_eye_y-camera_view_y; 
   float vvz = camera_eye_z-camera_view_z;
   float vvnorm = std::sqrt( vvx*vvx + vvy*vvy + vvz*vvz );
   vvx /= vvnorm;
   vvy /= vvnorm;
   vvz /= vvnorm;


// Rotate around y axis
//      Rotate view direction
   float cosx = std::cos( -dx*0.006 );
   float sinx = std::sin( -dx*0.006 );
   float nvvx = vvx*cosx + vvz*sinx;
   float nvvz = -vvx*sinx + vvz*cosx;
   float nrightx = camera_right_x*cosx + camera_right_z*sinx;
   float nrightz = -camera_right_x*sinx + camera_right_z*cosx;
   vvx = nvvx;
   vvz = nvvz;
   camera_right_x = nrightx;
   camera_right_z = nrightz;
//      Rotate up direction
   float crossx = camera_up_z;
   float crossy = 0.0;
   float crossz = -camera_up_x;
   float ydotup = camera_up_y;
   camera_up_x = camera_up_x*cosx + crossx*sinx;
   camera_up_y = camera_up_y*cosx + ydotup*(1.0-cosx) + crossy*sinx;
   camera_up_z = camera_up_z*cosx + crossz*sinx;
//      Rotate right direction
   crossx = camera_right_z;
   crossy = 0.0;
   crossz = -camera_right_x;
   ydotup = camera_right_y;
   camera_right_x = camera_right_x*cosx + crossx*sinx;
   camera_right_y = camera_right_y*cosx + ydotup*(1.0-cosx) + crossy*sinx;
   camera_right_z = camera_right_z*cosx + crossz*sinx;


// Rotate around camera-right axis
//     Rotate view direction
   cosx = std::cos( dy*0.006 );
   sinx = std::sin( dy*0.006 );
   float rightdotview = camera_right_x*vvx + camera_right_y*vvy + camera_right_z*vvz;
   crossx = camera_right_y*vvz - camera_right_z*vvy;
   crossy = camera_right_z*vvx - camera_right_x*vvz;
   crossz = camera_right_x*vvy - camera_right_y*vvx;
   nvvx = vvx*cosx + camera_right_x*rightdotview*(1.0-cosx) + crossx*sinx; 
   float nvvy = vvy*cosx + camera_right_y*rightdotview*(1.0-cosx) + crossy*sinx; 
   nvvz = vvz*cosx + camera_right_z*rightdotview*(1.0-cosx) + crossz*sinx; 
   vvx = nvvx;
   vvy = nvvy;
   vvz = nvvz;
//      Rotate up direction
   crossx = camera_right_y*camera_up_z - camera_right_z*camera_up_y;
   crossy = camera_right_z*camera_up_x - camera_right_x*camera_up_z;
   crossz = camera_right_x*camera_up_y - camera_right_y*camera_up_x;
   camera_up_x = camera_up_x*cosx + crossx*sinx; 
   camera_up_y = camera_up_y*cosx + crossy*sinx; 
   camera_up_z = camera_up_z*cosx + crossz*sinx; 


   camera_eye_x = vvx*vvnorm + camera_view_x;
   camera_eye_y = vvy*vvnorm + camera_view_y;
   camera_eye_z = vvz*vvnorm + camera_view_z;
}

void VzlViewer::ComputeEyeShift(float dz)
{
   float vvx = camera_eye_x-camera_view_x; 
   float vvy = camera_eye_y-camera_view_y; 
   float vvz = camera_eye_z-camera_view_z;
   float vvnorm = std::sqrt( vvx*vvx + vvy*vvy + vvz*vvz );
   vvx /= vvnorm;
   vvy /= vvnorm;
   vvz /= vvnorm;

   camera_eye_x += dz*vvx;
   camera_eye_y += dz*vvy;
   camera_eye_z += dz*vvz;
}

void VzlViewer::AddThing( vzl::VzlThing& t ) 
{ 
   things.push_back(t); 
   t->viewer = this;
   std::cout << t->Name() << " added to viewer.\n";
}


void VzlViewer::SetCameraEyeViewUp( float eyex, float eyey, float eyez, float viewx, float viewy, float viewz, float upx, float upy, float upz )
{
   camera_eye_x = eyex;   
   camera_eye_y = eyey;   
   camera_eye_z = eyez;   
   camera_view_x = viewx;   
   camera_view_y = viewy;   
   camera_view_z = viewz;   
   camera_up_x = upx;   
   camera_up_y = upy;   
   camera_up_z = upz;   
}



VzlViewer* CreateViewer() { return VzlViewer::Instance(); }



}


