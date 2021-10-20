//-------------------------------------------------------
//
//  Plane.C
//
//  Copyright (c) 2020 Jerry Tessendorf
//
//
//--------------------------------------------------------

#include "Plane.h"


using namespace std;

using namespace vzl;

Plane::Plane( const Vector& point, const Vector& N ) :
  reference_point(point),
  normal(N.unitvector())
{}


Plane::~Plane(){}


const Vector& Plane::Point() const { return reference_point; }
const Vector& Plane::Normal() const { return normal; }



double Plane::signed_distance( const Vector& P ) const
{
   return normal*(P-reference_point);
}



Vector Plane::project( const Vector& P ) const
{
   return P - signed_distance(P)*normal;
}



bool Plane::detect_intersection( const Vector& start, const Vector& end, double& location ) const
{
   double sd_start = signed_distance(start);
   double sd_end   = signed_distance(end);

   if( sd_start*sd_end > 0.0 ){ return false; }

   if( sd_start == 0.0 ){ location = 0.0; return true; }

   if( sd_end == 0.0 ){ location = 1.0; return true; }

   location = sd_start/(sd_start-sd_end);
   return true;

}







