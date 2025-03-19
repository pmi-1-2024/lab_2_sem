#pragma once
#include "Horse.h"
#include "Donkey.h"

class Zebroid : public Horse, public Donkey {
private:
    string pattern; // Візерунок забарвлення (смужки)

public:
    Zebroid() : Animal("", 0), Horse("", 0, "", ""), Donkey("", 0, "", 0.0, 0.0), pattern("") {}
    Zebroid(string name, int birthYear, string color, string breed, double earLength, string pattern)
        : Animal(name, birthYear), Horse(name, birthYear, color, breed), Donkey(name, birthYear, "", 0.0, earLength), pattern(pattern) {}

    void print(ostream& os) const override;
    void read(istream& is) override;

    friend ostream& operator<<(ostream& os, const Zebroid& z);
    friend istream& operator>>(istream& is, Zebroid& z);
};