#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string index, city, street;
public:
    Address(string index = "", string city = "", string street = "")
        : index(index), city(city), street(street) {
    }

    void display() const {
        cout << index << ", " << city << ", " << street << endl;
    }

    string getIndex() const { return index; }
    string getCity() const { return city; }
    string getStreet() const { return street; }
};
#endif