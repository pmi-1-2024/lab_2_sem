#include "Mule.h"
#include <iostream>

using namespace std;

Mule::Mule(const string& name, int year, const string& nickname)
    : Animal(name, year), nickname(nickname) {
}

void Mule::print(ostream& out) const {
    out << "Mule: " << name << ", Year: " << birthYear << ", Nickname: " << nickname << "\n";
}