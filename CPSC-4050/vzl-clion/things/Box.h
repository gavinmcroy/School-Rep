//-------------------------------------------------------
//
//  Box.h
//
//  Representations of boxes
//
//  Copyright (c) 2020 Jerry Tessendorf
//
//
//--------------------------------------------------------

#include <vector>
#include "Plane.h"
#include "../include/Vector.h"
#include "../include/Color.h"


using namespace std;

namespace vzl{

class Box
{
  public:

    Box(const Vector &llc, const Vector &urc);
   ~Box();

    const std::vector<Vector>& wall( int index ) const;
    const Color& wall_color( int index ) const;
   // const Plane& plane( int index ) const;

    size_t nb_walls() const { return walls.size(); }


    //size_t nb_planes() const { return planes.size(); }

    //bool detect_intersection( const Vector& start, const Vector& end, double& location, size_t& plane );

  private:

    Box(){

    };

    //std::vector<Plane> planes;

    // Each triangle_wall is four points in order.  This and triangleColor are for opengl display purposes.
    std::vector< std::vector<Vector> > walls;
    std::vector<Color> wall_colors;

};








}





