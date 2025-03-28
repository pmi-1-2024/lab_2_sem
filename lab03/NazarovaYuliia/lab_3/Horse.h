#pragma once
#include "Animal.h"
#include <string>
using namespace std;

class Horse : virtual public Animal { 
protected:
    string color, breed;
public:
    Horse() : Animal(), color(""), breed("") {}
    Horse(string name, int birthYear, string color, string breed)
        : Animal(name, birthYear), color(color), breed(breed) {}

    void print(ostream& os) const override;
    void read(istream& is) override;

    string getColor() const { return color; }
    string getBreed() const { return breed; }

    void setColor(string c) { color = c; }
    void setBreed(string b) { breed = b; }

    friend ostream& operator<<(ostream& os, const Horse& h);
    friend istream& operator>>(istream& is, Horse& h);
};

