#include "Cargo.h"

Cargo::Cargo() : name("noname"), weight(0.0), producing_country("nocoun") {}

Cargo::Cargo(string n, double w, string p_c) : name(n), weight(w), producing_country(p_c) {}

string Cargo::GetType() {
    return "Cargo";
}

string Cargo::GetName() {
    return name;
}

string Cargo::GetProdCountry() {
    return producing_country;
}

void Cargo::SetName(string nname) {
    name = nname;
}

void Cargo::SetWeight(double w) {
    weight = w;
}

void Cargo::SetProd_country(string p_c) {
    producing_country = p_c;
}

istream& operator>>(istream& is, Cargo& c) {
    is >> c.name >> c.weight >> c.producing_country;
    return is;
}

ostream& operator<<(ostream& os, const Cargo& c) {
    os << "\nName: " << c.name;
    os << "\nWeight: " << c.weight;
    os << "\nProducing country: " << c.producing_country;
    return os;
}
