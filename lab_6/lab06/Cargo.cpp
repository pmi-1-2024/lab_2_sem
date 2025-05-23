#include "Cargo.h"

Cargo::Cargo() : name(""), weight(0.0) {}
Cargo::Cargo(const string& name, double weight) : name(name), weight(weight) {}

void Cargo::setName(const string& name) {
    this->name = name;
}

void Cargo::setWeight(double weight) {
    this->weight = weight;
}

string Cargo::getName() const {
    return name;
}

double Cargo::getWeight() const {
    return weight;
}

ostream& operator<<(ostream& os, const Cargo& cargo) {
    os << "Cargo: " << cargo.name << " (" << cargo.weight << " kg)";
    return os;
}

istream& operator>>(istream& is, Cargo& cargo) {
    cout << "Enter gargo name: ";
    is >> cargo.name;
    cout << "Enter weight: ";
    is >> cargo.weight;
    return is;
}