#ifndef __FieldElement__
#include<cmath>
#include <boost/multiprecision/cpp_int.hpp>
#define __FieldElement__

class FieldElement
{
    public: 
    boost::multiprecision::cpp_int prime;
    boost::multiprecision::cpp_int num;

    bool operator==(const FieldElement& f1) const;
    bool operator!=(const FieldElement& f1) const;
    FieldElement operator+(const FieldElement& f1) const;
    FieldElement operator-(const FieldElement& f1) const;
    FieldElement operator*(const FieldElement& f1) const;
    FieldElement operator^(const FieldElement& f1) const;
    FieldElement operator/(const FieldElement& f1) const;
    static boost::multiprecision::cpp_int modulo(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int b, boost::multiprecision::cpp_int n);
    static boost::multiprecision::cpp_int modpow(boost::multiprecision::cpp_int base, boost::multiprecision::cpp_int exp, boost::multiprecision::cpp_int modulus);
   
    FieldElement(const boost::multiprecision::cpp_int num, const boost::multiprecision::cpp_int prime)
            : num(num), prime(prime){}
};

#endif // __FieldElement__