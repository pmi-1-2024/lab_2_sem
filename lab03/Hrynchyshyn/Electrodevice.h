#pragma once

#include <iostream>
#include <string>

using namespace std;

class Electrodevice {
protected:
    string brand;
    int price;
public:
    Electrodevice();
    Electrodevice(const string& b, int p);
    virtual ~Electrodevice();

    virtual void print(ostream& os) const = 0;
    virtual void read(istream& is);

    const string& getBrand() const;
    int getPrice() const;

    friend ostream& operator<<(ostream& os, const Electrodevice& e);
    friend istream& operator>>(istream& is, Electrodevice& e);
};


