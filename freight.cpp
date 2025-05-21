#include "Freight.h"


Freight::Freight() : item_name("noitem"), mass(0.0), origin_country("nocountry") {}

Freight::Freight(const string& name, double m, const string& origin) {
    SetName(name);
    SetMass(m);
    SetOrigin(origin);
}

string Freight::GetCategory() const {
    return "Freight";
}

string Freight::GetName() const {
    return item_name;
}

string Freight::GetOrigin() const {
    return origin_country;
}

void Freight::SetName(const string& name) {

    item_name = name;
}

void Freight::SetMass(double m) {

    mass = m;
}

void Freight::SetOrigin(const string& origin) {

    origin_country = origin;
}

istream& operator>>(istream& is, Freight& f) {
    is >> f.item_name >> f.mass >> f.origin_country;

    return is;
}

ostream& operator<<(ostream& os, const Freight& f) {
    os << "\nItem: " << f.item_name;
    os << "\nMass: " << f.mass;
    os << "\nOrigin country: " << f.origin_country;
    return os;
}