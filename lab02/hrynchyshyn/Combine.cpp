#include "Combine.h"

Combine::Combine() : power(0), functions(0) {}
Combine::Combine(const string& b, int p, int pow, int f)
    : Electrodevice(b, p), power(pow), functions(f) {
}

void Combine::print(ostream& os) const {
    os << "3 Name: Combine\nBrand: " << brand << "\nPrice: " << price
        << "\nPower: " << power << "\nCount of functions: " << functions << "\n";
}

void Combine::read(istream& is) {
    is >> brand >> price >> power >> functions;
}

ostream& operator<<(ostream& os, const Combine& device) {
    device.print(os);
    return os;
}

istream& operator>>(istream& is, Combine& device) {
    device.read(is);
    return is;
}