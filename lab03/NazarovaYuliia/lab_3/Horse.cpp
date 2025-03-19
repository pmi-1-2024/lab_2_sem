#include "Horse.h"

void Horse::print(ostream& os) const {
    Animal::print(os);
    os << ", Color: " << color << ", Breed: " << breed;
}

void Horse::read(istream& is) {
    Animal::read(is);
    is >> color >> breed;
}

ostream& operator<<(ostream& os, const Horse& h) {
    h.print(os);
    return os;
}

istream& operator>>(istream& is, Horse& h) {
    h.read(is);
    return is;
}