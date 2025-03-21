#include "Electroprilad.h"

Electroprilad::Electroprilad() : name(""), firm(""), price(0) {}

Electroprilad::Electroprilad(string n, string f, int p) : name(n), firm(f), price(p) {}

Electroprilad::Electroprilad(const Electroprilad& elp) : name(elp.name), firm(elp.firm), price(elp.price) {}

string Electroprilad::GetName() const {
    return name;
}

string Electroprilad::GetFirm() const {
    return firm;
}

int Electroprilad::GetPrice() const {
    return price;
}

bool Electroprilad::operator<(const Electroprilad& elp) const {
    return name < elp.name;
}

void Electroprilad::print(ostream& os) const {
    os << "Name: " << name << ", Firm: " << firm << ", Price: " << price << endl;
}

istream& operator>>(istream& is, Electroprilad& elp) {
    elp.write(is);
    return is;
}

ostream& operator<<(ostream& os, const Electroprilad& elp) {
    elp.print(os);
    return os;
}
