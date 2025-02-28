#pragma once

#include <string>
using namespace std;

class Address {
public:
    int zipcode;
    string city;
    string street;

    Address();
    void setAddress(int code, const string& c, const string& s);
    void print() const;
};