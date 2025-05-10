#include "Horse.h"
#include <iostream>

using namespace std;

Horse::Horse(const string& name, int year, const string& color, const string& breed)
    : Animal(name, year), color(color), breed(breed) {
}

void Horse::print(ostream& out) const {
    out << "Horse: " << name << ", Year: " << birthYear << ", Color: " << color << ", Breed: " << breed << "\n";
}

const string& Horse::getColor() const {
    return color;
}