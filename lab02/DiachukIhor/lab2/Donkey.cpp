#include "Donkey.h"
#include <iostream>

Donkey::Donkey(const std::string& name, int year, const std::string& species, double height)
    : Animal(name, year), species(species), height(height) {
}

void Donkey::print(std::ostream& out) const {
    out << "Donkey: " << name << ", Year: " << birthYear << ", Species: " << species << ", Height: " << height << "m\n";
}

double Donkey::getHeight() const {
    return height;
}
