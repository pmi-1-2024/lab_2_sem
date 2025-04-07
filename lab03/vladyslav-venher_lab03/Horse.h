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

    bool isWhiteHorse() const override { return color == "white"; }

    void read(istream& is) override {
        is >> name >> birthYear >> color >> breed;
    }

    void print(ostream& os) const override {
        os << "Horse: " << name << ", " << birthYear
            << ", Color: " << color << ", Breed: " << breed << '\n';
    }
};

#endif