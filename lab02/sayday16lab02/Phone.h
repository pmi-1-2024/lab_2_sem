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
    Phone();
    Phone(string n, string b, double p);
    virtual ~Phone();

    virtual void display() const = 0;
    virtual bool hasAnsweringMachine() const;

    double getPrice() const;

    friend istream& operator>>(istream& in, Phone*& p);
};

#endif
