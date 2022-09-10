//-------------------------------------------------------
//
//  Box.C
//
//  Copyright (c) 2020 Jerry Tessendorf
//
//
//--------------------------------------------------------

#include "Box.h"


using namespace std;

using namespace vzl;

Box::Box( const Vector& llc, const Vector& urc )
{
   for(int i=0;i<100;i++){ drand48(); }

   planes.push_back( Plane(llc, Vector(-1,0,0)) );
   planes.push_back( Plane(llc, Vector(0,-1,0)) );
   planes.push_back( Plane(llc, Vector(0,0,-1)) );
   planes.push_back( Plane(urc, Vector(1,0,0)) );
   planes.push_back( Plane(urc, Vector(0,1,0)) );
   planes.push_back( Plane(urc, Vector(0,0,1)) );


  // Faces based on llc
      std::vector<Vector> face;

/****************************************************************************/
 
      face.push_back(llc);
      face.push_back(Vector(llc[0], llc[1], urc[2] ));
      face.push_back(Vector(llc[0], urc[1], urc[2] ));
      face.push_back(Vector(llc[0], urc[1], llc[2] ));
      walls.push_back(face);
      wall_colors.push_back( Color(drand48(), drand48(), drand48(), 0 ) );
      face.clear();

/********************************************************************************/


      face.push_back(llc);
      face.push_back(Vector(llc[0], llc[1], urc[2] ));
      face.push_back(Vector(urc[0], llc[1], urc[2] ));
      face.push_back(Vector(urc[0], llc[1], llc[2] ));
      walls.push_back(face);
      wall_colors.push_back( Color(drand48(), drand48(), drand48(), 0 ) );
      face.clear();


/****************************************************************************/

      face.push_back(llc);
      face.push_back(Vector(llc[0], urc[1], llc[2] ));
      face.push_back(Vector(urc[0], urc[1], llc[2] ));
      face.push_back(Vector(urc[0], llc[1], llc[2] ));
      walls.push_back(face);
      wall_colors.push_back( Color(drand48(), drand48(), drand48(), 0 ) );
      face.clear();

/********************************************************************************/




// Faces based on urc


/*********************************************************************************/
  
      face.push_back(urc);
      face.push_back(Vector(urc[0], urc[1], llc[2] ));
      face.push_back(Vector(urc[0], llc[1], llc[2] ));
      face.push_back(Vector(urc[0], llc[1], urc[2] ));
      walls.push_back(face);
      wall_colors.push_back( Color(drand48(), drand48(), drand48(), 0 ) );
      face.clear();





      face.push_back(urc);
      face.push_back(Vector(urc[0], urc[1], llc[2] ));
      face.push_back(Vector(llc[0], urc[1], llc[2] ));
      face.push_back(Vector(llc[0], urc[1], urc[2] ));
      walls.push_back(face);
      wall_colors.push_back( Color(drand48(), drand48(), drand48(), 0 ) );
      face.clear();





      face.push_back(urc);
      face.push_back(Vector(urc[0], llc[1], urc[2] ));
      face.push_back(Vector(llc[0], llc[1], urc[2] ));
      face.push_back(Vector(llc[0], urc[1], urc[2] ));
      walls.push_back(face);
      wall_colors.push_back( Color(drand48(), drand48(), drand48(), 0 ) );
      face.clear();

/***********************************************************************************/


}

Box::~Box(){}

const std::vector<Vector>& Box::wall( int index ) const
{
   return walls[index];
}

const Color& Box::wall_color( int index ) const
{
   return wall_colors[index];
}


const Plane& Box::plane( int index ) const
{
   return planes[index];
}



bool Box::detect_intersection( const Vector& start, const Vector& end, double& location, size_t& plane_index )
{
   location = 2.0;
   for( size_t i=0;i<planes.size();i++)
   {
      double loc = 2.0;
      const Plane& p = plane(i);
      if( p.detect_intersection(start,end,loc) )
      {
         if( loc < location)
	 {
	    location = loc;
	    plane_index = i;
	 }
      }
   }
   return (location < 2.0 ) ? true : false;
}
