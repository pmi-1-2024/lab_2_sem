#pragma once
#include "Animal.h"
#include <string>
using namespace std;

class Horse : virtual public Animal { // Virtual imitation
protected:
    string color, breed;
public:
    Horse(string name, int birthYear, string color, string breed)
        : Animal(name, birthYear), color(color), breed(breed) {}
    void print(ostream& out) const override;
    string getColor() const { return color; }
};

