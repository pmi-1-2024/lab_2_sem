#include "Combine.h"

Combine::Combine() : Electrodevice(), power(0), functions(0) {}

Combine::Combine(const string& b, int p, int pow, int f)
    : Electrodevice(b, p), power(pow), functions(f) {
}

void Combine::print(ostream& os) const {
    os << "Combine\nBrand: " << brand << "\nPrice: " << price << "\nPower: " << power << "\nFunctions: " << functions << "\n";
}

void Combine::read(istream& is) {
    Electrodevice::read(is);
    is >> power >> functions;
}

int Combine::getCombinePower() const {
    return power;
}

int Combine::getFunctions() const {
    return functions;
}