#pragma once
#ifndef PHONE_H
#define PHONE_H

#include <iostream>
using namespace std;

class Phone {
protected:
    string name;
    string brand;
    double price;
public:
    Phone(string n, string b, double p);
    virtual void print(ostream& out) const;
    double getPrice() const;
    virtual ~Phone();
};

#endif // PHONE_H