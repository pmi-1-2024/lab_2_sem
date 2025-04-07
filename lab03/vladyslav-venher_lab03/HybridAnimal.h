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

    bool isWhiteHorse() const override { return Horse::isWhiteHorse(); }
    bool isShortDonkey() const override { return Donkey::isShortDonkey(); }

    void read(istream& is) override {
        is >> name >> birthYear >> Horse::color >> Horse::breed >> Donkey::type >> Donkey::height >> hybridName;
    }

    void print(ostream& os) const override {
        os << "HybridAnimal: " << name << ", " << birthYear
            << ", Color: " << Horse::color
            << ", Breed: " << Horse::breed
            << ", Type: " << Donkey::type
            << ", Height: " << Donkey::height << "m"
            << ", Nickname: " << hybridName << '\n';
    }
};

#endif
