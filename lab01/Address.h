#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
using namespace std;

class Address {
private:
    string zipCode;
    string city;
    string street;

public:
    Address(string zip, string c, string s) : zipCode(zip), city(c), street(s) {}

    friend ostream& operator<<(ostream& out, const Address& addr);
    friend istream& operator>>(istream& in, Address& addr);
};

#endif
