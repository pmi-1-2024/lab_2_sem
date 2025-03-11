#include "Donkey.h"

void Donkey::print(ostream& os) const {
    Animal::print(os);
    os << ", Type: " << type << ", Height: " << height;
}
void Donkey::read(istream& is) {
    Animal::read(is);
    is >> type >> height;
}

ostream& operator<<(ostream& os, const Donkey& d) {
    d.print(os);
    return os;
}

istream& operator>>(istream& is, Donkey& d) {
    d.read(is);
    return is;
}