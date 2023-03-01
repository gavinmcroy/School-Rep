//-------------------------------------------------------
//
//  Plane.h
//
//  Plane class for display and collision logic
//
//  Copyright (c) 2020 Jerry Tessendorf
//
//
//--------------------------------------------------------


#include "../include/Vector.h"
#include "../include/Color.h"

using namespace std;

namespace vzl{

class Plane
{
  public:

    Plane( const Vector& point, const Vector& normal );
   ~Plane();

    const Vector& Point() const;
    const Vector& Normal() const;


    double signed_distance( const Vector& P ) const;

    Vector project( const Vector& P ) const;

    bool detect_intersection( const Vector& start, const Vector& end, double& location ) const;

  private:

    Plane(){};

    Vector reference_point;
    Vector normal;


};

}





