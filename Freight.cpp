#include "Freight.h"
#include "CustomException.h"

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
    if (name.empty()) throw CustomException("Item name cannot be empty.");
    item_name = name;
}

void Freight::SetMass(double m) {
    if (m <= 0) throw CustomException("Mass must be positive.");
    mass = m;
}

void Freight::SetOrigin(const string& origin) {
    if (origin.empty()) throw CustomException("Origin cannot be empty.");
    origin_country = origin;
}

istream& operator>>(istream& is, Freight& f) {
    is >> f.item_name >> f.mass >> f.origin_country;
    if (!is) throw std::runtime_error("Error reading Freight from stream");
    return is;
}

ostream& operator<<(ostream& os, const Freight& f) {
    os << "\nItem: " << f.item_name;
    os << "\nMass: " << f.mass;
    os << "\nOrigin country: " << f.origin_country;
    return os;
}