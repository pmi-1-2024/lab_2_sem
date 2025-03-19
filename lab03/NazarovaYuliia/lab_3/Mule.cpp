#include "Mule.h"

void Mule::print(ostream& os) const {
    Animal::print(os);
    os << ", Color: " << Horse::getColor() << ", Type: " << type << ", Height: " << height << ", Nickname: " << nickname;
}

void Mule::read(istream& is) {
    Animal::read(is);
    Horse::read(is);
    Donkey::read(is);
    is >> nickname;
}

ostream& operator<<(ostream& os, const Mule& m) {
    m.print(os);
    return os;
}

istream& operator>>(istream& is, Mule& m) {
    m.read(is);
    return is;
}