#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
using namespace std;

class Address {
private:
    string index, city, street;
public:
    Address(string index, string city, string street);
    void display() const;
    string getIndex() const;
    string getCity() const;
    string getStreet() const;
};
#endif 
