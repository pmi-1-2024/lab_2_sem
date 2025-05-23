#include "Cargo.h"

Cargo::Cargo(const string& type) : type(type) {}

string Cargo::getType() const {
    return type;
}

void Cargo::setType(const string& newType) {
    type = newType;
}

bool Cargo::operator==(const string& str) const {
    return type == str;
}

ostream& operator<<(ostream& os, const Cargo& item) {
    os << item.type;
    return os;
}

istream& operator>>(istream& is, Cargo& item) {
    is >> item.type;
    return is;
}