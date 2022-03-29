#include <iostream>
#include "FieldElement.h"
#include "Point.h"
#include "math.h"
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

// These are the Recommended Elliptic Curve Domain Parameters from the Standards for Efficient Cryptography 2 (SEC 2) - https://www.secg.org/sec2-v2.pdf
const cpp_int GX("0x79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798");
const cpp_int GY("0x483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8");
const cpp_int P("115792089237316195423570985008687907853269984665640564039457584007908834671663");
const cpp_int N("115792089237316195423570985008687907852837564279074904382605163141518161494337");

// TODO: Put these funtions into a class.
Point getPublicKey(cpp_int privatekey)
{

    FieldElement x(GX,P);
    FieldElement y(GY,P);
    FieldElement a(0,P);
    FieldElement b(7,P);
    Point g(x,y,a,b);

    // To get the Public Address from a private key we mutiply the Generator Point by our private key.
    return g*privatekey;
}

bool verifySignature(cpp_int z,cpp_int r, cpp_int s, cpp_int publicX, cpp_int publicY)
{
    cpp_int s_inv("");
    cpp_int u("");
    cpp_int v("");

    FieldElement pubkxfield(publicX,P);
    FieldElement pubkyfield(publicY,P);

    FieldElement a(0,P);
    FieldElement b(7,P);

    Point pubkpoint(pubkxfield,pubkyfield,a,b);

    FieldElement x1(GX,P);
    FieldElement y1(GY,P);

    Point g(x1,y1,a,b);

    s_inv = FieldElement::modulo(s,N-2,N);

    u = z * s_inv % N;
    v = r * s_inv % N;

    return (g*u + pubkpoint*v).x.num == r;
}

void signSignature(cpp_int z, cpp_int k, cpp_int pk){

    cpp_int r("");
    cpp_int k_inv("");
    cpp_int s("");

    FieldElement x1(GX,P);
    FieldElement y1(GY,P);

    FieldElement a(0,P);
    FieldElement b(7,P);

    Point g(x1,y1,a,b);

    r = (g*k).x.num;
    k_inv = FieldElement::modulo(k,N-2,N);
    s = (z+r*pk) * k_inv % N;

    cout << "Z: " << std::hex << z;
    cout << "\n";
    cout << "R: " << std::hex << r;
    cout << "\n";
    cout << "S: " << std::hex << s;

}

int main() {

    
    // Get public key from private key.
    cpp_int pk("0x01");

    cout << "x: " << std::hex << getPublicKey(pk).x.num;
    cout << "\n\n";
    cout << "y: " << std::hex << getPublicKey(pk).y.num;

    /*cpp_int z("0x01");
    signSignature(z,1234567,pk);
    
    // Verify a signature (message).
    cpp_int z("0x01");
    cpp_int r("0x01");
    cpp_int s("0x01");

    cpp_int pubkx("0x01");
    cpp_int pubky("0x01");

    cout << verifySignature(z,r,s,pubkx,pubky);*/

    return 0;
}