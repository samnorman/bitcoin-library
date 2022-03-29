# bitcoin-library
Bitcoin Library for Test Transaction. 

Work in progress - A bitcoin utility library used for signing and verifying transactions on the Bitcoin testnet - plus other useful bitcoin goodness. 

Warning: To be used for reference and educational purposes only. Don't use on the Bitcoin Mainnet or any other production cryptography systems.  

Usage: -

To Compile: -

g++ main.cpp FieldElement.cpp Point.cpp -o main

Get public key from private key: -

cpp_int pk("Private Key Here");

cout << "x: " << std::hex << getPublicKey(pk).x.num;
cout << "y: " << std::hex << getPublicKey(pk).y.num;

Sign a message: -

z is the message.
k is a super random number.
pk is your private key.
cpp_int pk("Private Key Here");
cpp_int z("Message");

signSignature(z,1234567,pk);

Verifying a signature: -

cpp_int z("Message");
cpp_int r("R Value from sign");
cpp_int s("S Signature from sign");

cpp_int pubkx("Public X Key");
cpp_int pubky("Public Y Key");

cout << verifySignature(z,r,s,pubkx,pubky);

Todo: -

Lots!

Ref: -

Boost library for the 256 bit Variables - https://www.boost.org
Recommended Elliptic Curve Domain Parameters from the Standards for Efficient Cryptography 2 (SEC 2) - https://www.secg.org/sec2-v2.pdf
