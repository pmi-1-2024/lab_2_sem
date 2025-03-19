#include "Zebroid.h"

void Zebroid::print(ostream& os) const {
    Animal::print(os);
    os << ", Color: " << Horse::getColor() << ", Breed: " << Horse::getBreed() << ", Ear Length: " << Donkey::getEarLength() << ", Pattern: " << pattern;
}

void Zebroid::read(istream& is) {
    Animal::read(is);
    Horse::read(is);
    is >> earLength;
    is >> pattern;
}

ostream& operator<<(ostream& os, const Zebroid& z) {
    z.print(os);
    return os;
}

istream& operator>>(istream& is, Zebroid& z) {
    z.read(is);
    return is;
}