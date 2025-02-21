#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
using namespace std;

class Address {
public:
    string zipCode;
    string city;
    string street;

    Address(string zip, string c, string s) : zipCode(zip), city(c), street(s) {}
    void display() const;
};
#endif

