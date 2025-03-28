#include "Electrodevice.h"

Electrodevice::Electrodevice() : brand(""), price(0) {}

Electrodevice::Electrodevice(const string& b, int p) : brand(b), price(p) {}

Electrodevice::~Electrodevice() {}

void Electrodevice::read(std::istream& is) {
    is >> brand >> price;
}

const string& Electrodevice::getBrand() const { return brand; }

int Electrodevice::getPrice() const { return price; }

ostream& operator<<(ostream& os, const Electrodevice& e) {
    e.print(os);
    return os;
}

istream& operator>>(istream& is, Electrodevice& e) {
    e.read(is);
    return is;
}
