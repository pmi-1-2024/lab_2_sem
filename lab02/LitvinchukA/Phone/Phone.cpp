#include "Phone.h"

Phone::Phone(const string& name, const string& brand, double price)
    : name(name), brand(brand), price(price) {
}

string Phone::getName() const {
    return name;
}

string Phone::getBrand() const {
    return brand;
}

double Phone::getPrice() const {
    return price;
}

ostream& operator<<(ostream& os, const Phone& phone) {
    os << phone.name << " " << phone.brand << " " << phone.price;
    return os;
}

istream& operator>>(istream& is, Phone& phone) {
    is >> phone.name >> phone.brand >> phone.price;
    return is;
}