//-------------------------------------------------------
//
//  MyThing.C
//
//  VzlThing for a collection of particles
//  each doing a random walk.
//
//  Copyright (c) 2017 Jerry Tessendorf
//
//
//--------------------------------------------------------
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#include "MyThing.h"
#include <cstdlib>
#include <iostream>
#include <omp.h>

using namespace std;

using namespace vzl;


#include "VzlViewer.h"


MyThing::MyThing(const std::string nam) :
 VzlThingyDingy (nam),
 box        (Box(Vector(-4*drand48(),-4*drand48(),-4*drand48()), Vector(4*drand48(),4*drand48(),4*drand48()))),
 show_all_sides (false),
 display_wire(false)
{
    std::cout << name << " constructed\n";
}

MyThing::~MyThing(){}

// Not doing anything here
void MyThing::Init( const std::vector<std::string>& args ) {}


// Display your geometry in opengl 
// This is old-style opengl.
void MyThing::Display() 
{
   if(display_wire)
   {
      // Draw box as wireframe
      glBegin(GL_LINES);
      for( size_t i=0;i<box.nb_walls();i++ )
      {
         const Color& ci = box.wall_color(i);
         glColor3f( ci.red(), ci.green(), ci.blue() );
         const std::vector<Vector>& wall = box.wall(i);
         for( size_t p=0;p<wall.size()-1;p++ )
         {
            glVertex3f( wall[p].X(), wall[p].Y(), wall[p].Z() );
            glVertex3f( wall[p+1].X(), wall[p+1].Y(), wall[p+1].Z() );
         }
         glVertex3f( wall[wall.size()-1].X(), wall[wall.size()-1].Y(), wall[wall.size()-1].Z() );
         glVertex3f( wall[0].X(), wall[0].Y(), wall[0].Z() );
      }
      glEnd();

   }
   else
   {
      // Draw box as quads
      glBegin(GL_QUADS);
      for( size_t i=0;i<box.nb_walls();i++ )
      {
         if( i != 2 || show_all_sides )
         {
            const Color& ci = box.wall_color(i);
            glColor3f( ci.red(), ci.green(), ci.blue() );
            const std::vector<Vector>& wall = box.wall(i);
            for( size_t p=0;p<wall.size();p++ )
            {
               glVertex3f( wall[p].X(), wall[p].Y(), wall[p].Z() );
            }
         }
      }
      glEnd();
   }
}



// This is where we act upon keyboard hits by the user
// to change parameter values or take action
void MyThing::Keyboard( unsigned char key, int x, int y )
{
   VzlThingyDingy::Keyboard(key,x,y);
   // Put more keyboard actions here that are specific to this thing
   if( key == 's' )
   {
      show_all_sides = !show_all_sides;
      if(show_all_sides){ cout << "Showing all sides\n";}
      else { cout << "Not showing all sides\n"; }
   }
   if( key == 'w' )
   {
      display_wire = !display_wire;
      if(display_wire){ cout << "Wireframe display\n";}
      else { cout << "Solid display\n"; }
   }
}



void MyThing::Usage()
{
   VzlThingyDingy::Usage();
   cout << "=== " << name << " ===\n";
   // Put usage here that is specific to this thing
   cout << "s         toggles whether to show all sides of the box\n";
   cout << "w         toggles whether to use wireframe display\n";
}


vzl::VzlThing vzl::CreateMyThing(){ return VzlThing( new MyThing() ); }


