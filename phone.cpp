#include "Phone.h"

Phone::Phone(string n, string b, double p) : name(n), brand(b), price(p) {}

void Phone::print(ostream& out) const {
    out << brand << " " << name << " " << price;
}

double Phone::getPrice() const { return price; }

Phone::~Phone() {}