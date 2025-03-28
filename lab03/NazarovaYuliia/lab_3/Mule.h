#pragma once
#include "Horse.h"
#include "Donkey.h"
using namespace std;

class Mule : public Horse, public Donkey {
    string nickname;
public:
    Mule() : Animal(), Horse(), Donkey(), nickname("") {}
    Mule(string name, int birthYear, string color, string breed, string type, double height, double earLength, string nickname)
        : Animal(name, birthYear), Horse(name, birthYear, color, breed), Donkey(name, birthYear, type, height, earLength), nickname(nickname){}

    void print(ostream& os) const override;
    void read(istream& is) override;

    friend ostream& operator<<(ostream& os, const Mule& m);
    friend istream& operator>>(istream& is, Mule& m);
};
