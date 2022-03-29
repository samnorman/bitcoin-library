#include "Point.h"
#include <limits>

bool Point::operator!=(const Point& p1) const
{
    return !(*this == p1);
}

bool Point::operator==(const Point& p1) const
{
    return x == p1.x && y == p1.y && a == p1.a && b == p1.b;
}

Point Point::operator*(boost::multiprecision::cpp_int number) const
{
    number = number -1;

    Point current = *this;
    Point p1 = *this;

    cpp_int numberloop = number;

    while (numberloop) {
        if(numberloop & 1) {
            p1 = p1+current;
        }
        current = current+current;
        numberloop >>= 1;
    }
   
    return p1;
}

Point Point::operator+(const Point& p1) const
{

    FieldElement two(2,x.prime);
    FieldElement three(3,x.prime);

    if(a != p1.a || b != p1.b) {
        // TODO: Error here.
    } 

    // TODO: Look at returning inf.
    if(x.num == std::numeric_limits<int>::max()){
        return p1;
    }

    if(p1.x.num == std::numeric_limits<int>::max()){
        return *this;
    }

    if (x == p1.x and y != p1.y){
        return Point(FieldElement(std::numeric_limits<int>::max(),x.prime), FieldElement(std::numeric_limits<int>::max(),x.prime), a, b);
    }

    if(x != p1.x) {
        FieldElement s = (p1.y - y) / (p1.x - x);
        FieldElement x1 = (s^two) - x - p1.x;
        FieldElement y1 = s * (x - x1) - y;
        return Point(x1, y1, a, b);
    }

    if(*this == p1) {
        FieldElement s = (three * (x^two) + a) / (two * y);
        FieldElement x1 = (s^two) - two * x;
        FieldElement y1 = s * (x - x1) - y;
        return Point(x1, y1, a, b);
    }

    return Point(p1);
}