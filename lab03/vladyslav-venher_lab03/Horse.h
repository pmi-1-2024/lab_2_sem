#ifndef HORSE_H
#define HORSE_H

#include "Animal.h"

class Horse : virtual public Animal {
protected:
    string color, breed;

public:
    Horse(const string& name = "", int birthYear = 0, const string& color = "", const string& breed = "")
        : Animal(name, birthYear), color(color), breed(breed) {
    }

    void display(ostream& os) const override {
        os << "Horse: " << name << ", " << birthYear
            << ", Color: " << color << ", Breed: " << breed << '\n';
    }
    bool isWhiteHorse() const override { return color == "white"; }
};

#endif