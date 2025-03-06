#pragma once
#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    int zipcode;
    string city;
    string street;
public:
    Address();
    Address(int code, const string& c, const string& s);
    friend ostream& operator<<(ostream& os, const Address& a);
    friend istream& operator>>(istream& is, Address& a);
};