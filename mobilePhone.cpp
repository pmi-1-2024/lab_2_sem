#include "MobilePhone.h"

MobilePhone::MobilePhone(string n, string b, double p, string c, int m)
    : Phone(n, b, p), color(c), memory(m) {}

void MobilePhone::print(ostream& out) const {
    out << brand << " " << name << " " << price << " " << color << " " << memory;
}