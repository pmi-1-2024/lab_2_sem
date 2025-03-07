#pragma once
#include "Horse.h"
#include "Donkey.h"
using namespace std;

class Mule : public Horse, public Donkey {
    string nickname;
public:
    Mule(string name, int birthYear, string color, string breed, string type, double height, string nickname)
        : Animal(name, birthYear), Horse(name, birthYear, color, breed), Donkey(name, birthYear, type, height), nickname(nickname) {}
    void print(ostream& out) const override;
};























































