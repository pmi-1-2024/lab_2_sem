#include "Mule.h"
#include <iostream>

Mule::Mule(const std::string& name, int year, const std::string& nickname)
    : Animal(name, year), nickname(nickname) {
}

void Mule::print(std::ostream& out) const {
    out << "Mule: " << name << ", Year: " << birthYear << ", Nickname: " << nickname << "\n";
}
