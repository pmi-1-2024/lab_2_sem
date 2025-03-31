#include "Donkey.h"
#include <iostream>

using namespace std;

Donkey::Donkey(const string& name, int year, const string& species, double height)
    : Animal(name, year), species(species), height(height) {
}

void Donkey::print(ostream& out) const {
    out << "Donkey: " << name << ", Year: " << birthYear << ", Species: " << species << ", Height: " << height << "m\n";
}

double Donkey::getHeight() const {
    return height;
}