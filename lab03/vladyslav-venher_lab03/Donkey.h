#ifndef DONKEY_H
#define DONKEY_H

#include "Animal.h"

class Donkey : virtual public Animal {
protected:
    string type;
    double height;

public:
    Donkey(const string& name = "", int birthYear = 0, const string& type = "", double height = 0)
        : Animal(name, birthYear), type(type), height(height) {
    }

    void display(ostream& os) const override {
        os << "Donkey: " << name << ", " << birthYear
            << ", Type: " << type << ", Height: " << height << "m\n";
    }
    bool isShortDonkey() const override { return height <= 1.5; }
};

#endif