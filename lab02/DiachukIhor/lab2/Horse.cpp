#include "Horse.h"
#include <iostream>

Horse::Horse(const std::string& name, int year, const std::string& color, const std::string& breed)
    : Animal(name, year), color(color), breed(breed) {
}

void Horse::print(std::ostream& out) const {
    out << "Horse: " << name << ", Year: " << birthYear << ", Color: " << color << ", Breed: " << breed << "\n";
}

const std::string& Horse::getColor() const {
    return color;
}
