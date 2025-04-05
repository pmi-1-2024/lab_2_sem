#ifndef PHONE_H
#define PHONE_H
#include <iostream>
#include <string>
using namespace std;

class Phone {
protected:
    string name;
    string brand;
    double price;
public:
    Phone(string name = "", string brand = "", double price = 0.0);
    virtual ~Phone() {}
    virtual void print(ostream& os) const = 0;
    virtual void read(istream& is) = 0;
    double getPrice() const { return price; }
    string getName() const { return name; }
    string getBrand() const { return brand; }
    friend ostream& operator<<(ostream& os, const Phone& p);
    friend istream& operator>>(istream& is, Phone& p);
};

#endif