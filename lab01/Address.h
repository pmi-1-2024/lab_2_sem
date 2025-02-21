#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address {
public:
    int index;
    string city;
    string street;

    Address(int n, string g, string f) : index(n), city(g), street(f) {}
};

#endif 
