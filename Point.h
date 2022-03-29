#ifndef __Point__
#include<cmath>
#include <iostream>
#include <limits>
#include "FieldElement.h"
using namespace boost::multiprecision;
#define __Point__
class Point{
    public:
        FieldElement x;
        FieldElement y;
        FieldElement a;
        FieldElement b;
        bool operator==(const Point& p1) const;
        bool operator!=(const Point& p1) const;
        Point operator+(const Point& p1) const;
        Point operator*(boost::multiprecision::cpp_int number) const;

    Point(FieldElement x, FieldElement y, FieldElement a, FieldElement b) : x(x), y(y), a(a), b(b){

        if(x.num == std::numeric_limits<int>::max() && y.num == std::numeric_limits<int>::max()) {
            return;
        }

        FieldElement two(2,x.prime);
        FieldElement three(3,x.prime);

        bool result = (y^two) != (x^three) + a * x + b;
    }

};


#endif // __Point__