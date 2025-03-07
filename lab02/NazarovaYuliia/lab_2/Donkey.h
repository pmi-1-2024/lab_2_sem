#pragma once
#include "Animal.h"
#include <string>
using namespace std;

class Donkey : virtual public Animal {
protected:
    string type;
    double height;
public:
    Donkey(string name, int birthYear, string type, double height)
        : Animal(name, birthYear), type(type), height(height) {}
    void print(ostream& out) const override;
    double getHeight() const { return height; }
};

