#ifndef MULE_H
#define MULE_H

#include "Horse.h"
#include "Donkey.h"
using namespace std;

class Mule : public Horse, public Donkey {
    string nickname;

public:
    Mule(const string& name = "", int birthYear = 0,
        const string& color = "", const string& breed = "",
        const string& type = "", double height = 0,
        const string& nickname = "")
        : Animal(name, birthYear), Horse(name, birthYear, color, breed),
        Donkey(name, birthYear, type, height), nickname(nickname) {
    }

    void read(istream& is) override {
        string color, breed, type;
        double height;
        is >> name >> birthYear >> color >> breed >> type >> height >> nickname;

        Horse::color = color;
        Horse::breed = breed;
        Donkey::type = type;
        Donkey::height = height;
    }

    void print(ostream& os) const override {
        os << "Mule: " << name << ", " << birthYear
            << ", Color: " << Horse::color
            << ", Breed: " << Horse::breed
            << ", Type: " << Donkey::type
            << ", Height: " << Donkey::height << "m"
            << ", Nickname: " << nickname << '\n';
    }

};

#endif
