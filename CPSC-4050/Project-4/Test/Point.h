#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <functional>
#include <iostream>
#include <cmath>


class Point
{
public:

    Point();

    Point(const float& x, const float& y);

    void toStream(std::ostream& output_stream) const;
    void fromStream(std::istream& input_stream);


    float x;
    float y;

};

std::ostream& operator<<(std::ostream& output_stream, const Point& point);
std::istream& operator>>(std::istream& input_stream, Point& point);


#endif // POINT_H_INCLUDED