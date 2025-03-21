#include "MobilePhone.h"

MobilePhone::MobilePhone() : Phone("", "", 0), color(""), memory(0) {}

MobilePhone::MobilePhone(const string& name, const string& brand, double price, const string& color, int memory)
    : Phone(name, brand, price), color(color), memory(memory) {
}

string MobilePhone::getColor() const { return color; }

int MobilePhone::getMemory() const { return memory; }

bool MobilePhone::operator<(const Phone& other) const {
    return price < other.getPrice();
}

void MobilePhone::input(istream& is) {
    is >> name >> brand >> price >> color >> memory;
}

istream& operator>>(istream& is, MobilePhone& phone) {
    phone.input(is);
    return is;
}

ostream& operator<<(ostream& os, const MobilePhone& phone) {
    os << phone.name << " " << phone.brand << " " << phone.price << " " << phone.color << " " << phone.memory;
    return os;
}