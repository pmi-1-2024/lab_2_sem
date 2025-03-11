#include "Mule.h"

void Mule::print(ostream& os) const {
    Animal::print(os);
    os << ", Color: " << Horse::getColor() << ", Type: " << type << ", Height: " << height << ", Nickname: " << nickname;
}

void Mule::read(istream& is) {
    string name;
    int birthYear;
    string color, breed, type, nickname;
    double height;
    Animal::read(is);
    Horse::read(is);
    Donkey::read(is);

    is >> name >> birthYear >> color >> breed >> type >> height >> nickname;

    this->name = name;
    this->birthYear = birthYear;
    this->color = color;
    this->breed = breed;
    this->type = type;
    this->height = height;
    this->nickname = nickname;
}

ostream& operator<<(ostream& os, const Mule& m) {
    m.print(os);
    return os;
}

istream& operator>>(istream& is, Mule& m) {
    m.read(is);
    return is;
}