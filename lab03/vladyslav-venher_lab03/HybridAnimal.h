#ifndef HYBRID_ANIMAL_H
#define HYBRID_ANIMAL_H

#include "Horse.h"
#include "Donkey.h"

class HybridAnimal : public Horse, public Donkey {
    string hybridName;

public:
    HybridAnimal(const string& name = "", int birthYear = 0, const string& color = "", const string& breed = "",
        const string& type = "", double height = 0, const string& hybridName = "")
        : Animal(name, birthYear), Horse(name, birthYear, color, breed),
        Donkey(name, birthYear, type, height), hybridName(hybridName) {
    }

    void display(ostream& os) const override {
        os << "Hybrid Animal: " << name << ", " << birthYear
            << ", Hybrid Name: " << hybridName << "\n";
    }
    bool isWhiteHorse() const override { return Horse::isWhiteHorse(); }
    bool isShortDonkey() const override { return Donkey::isShortDonkey(); }
};

#endif