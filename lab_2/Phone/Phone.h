#ifndef PHONE_H
#define PHONE_H

#include <string>
#include <iostream>
using namespace std;

class Phone {
protected:
    string name;
    string brand;
    double price;
public:
    Phone(const string& name, const string& brand, double price);
    virtual ~Phone() = default;

    string getName() const;
    string getBrand() const;
    double getPrice() const;

    friend istream& operator>>(istream& is, Phone*& phone);
    friend ostream& operator<<(ostream& os, const Phone& phone);
};

#endif
