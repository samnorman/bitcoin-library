#include "FieldElement.h"
#include <iostream>

bool FieldElement::operator==(const FieldElement& f1) const
{
    return num == f1.num && prime == f1.prime;
}

bool FieldElement::operator!=(const FieldElement& f1) const
{
    return !(*this == f1);
}

FieldElement FieldElement::operator+(const FieldElement& f1) const
{
    if(f1.prime != prime){
        // TODO: Error here.
    }
    boost::multiprecision::cpp_int num1 = (((num + f1.num) % prime) + prime) % prime;
    return FieldElement(num1,prime);
}

FieldElement FieldElement::operator-(const FieldElement& f1) const
{
    if(f1.prime != prime){
        // TODO: Error here.
    }

    boost::multiprecision::cpp_int num1 = (((num - f1.num) % prime) + prime) % prime;

    return FieldElement(num1,prime);
}

FieldElement FieldElement::operator*(const FieldElement& f1) const
{
    if(f1.prime != prime){
        // TODO: Error here.
    }
    boost::multiprecision::cpp_int num1 = (((num * f1.num) % prime) + prime) % prime;
    return FieldElement(num1,prime);
}

FieldElement FieldElement::operator/(const FieldElement& f1) const
{
    if(f1.prime != prime){
        // TODO: Error here.
    }

    boost::multiprecision::cpp_int num1 = num * FieldElement::modulo(f1.num,prime-2,prime) % prime;
    return FieldElement(num1,prime);
}

FieldElement FieldElement::operator^(const FieldElement& f1) const
{
    if(f1.prime != prime){
        // TODO: Error here.
    }
    boost::multiprecision::cpp_int n = ((prime - 1) + (f1.num%(prime - 1))) % (prime - 1);
    boost::multiprecision::cpp_int num1 = FieldElement::modulo(num,n,prime);
    return FieldElement(num1,prime);
}

// TODO: Take this into a helper file.
boost::multiprecision::cpp_int FieldElement::modulo(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int b, boost::multiprecision::cpp_int n){
    boost::multiprecision::cpp_int x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; 
        }
        y = (y*y) % n; 
        b /= 2;
    }
    return x % n;
}
