#pragma once
#include "Animal.h"
#include <string>
using namespace std;

class Donkey : virtual public Animal {
protected:
    string type;
    double height, earLength;
public:
    Donkey() : Animal(), type(""), height(0.0), earLength(0.0) {}
    Donkey(string name, int birthYear, string type, double height, double earLength)
        : Animal(name, birthYear), type(type), height(height), earLength(earLength) {}

    void print(ostream& os) const override;
    void read(istream& is)override;

    double getHeight() const { return height; }
    double getEarLength() const { return earLength; }

    friend ostream& operator<<(ostream& os, const Donkey& d);
    friend istream& operator>>(istream& is, Donkey& d);
};
