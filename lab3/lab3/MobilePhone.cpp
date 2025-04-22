#include "MobilePhone.h"

MobilePhone::MobilePhone(string n, string b, double p, string c, int m) : Phone(n, b, p), color(c), memory(m) {}

MobilePhone::MobilePhone() : Phone() {
    color = "";
    memory = 0;
}
//void MobilePhone::display() const {
//   cout << "Mobile Phone: " << name << ", " << brand << ", " << price << ", " << color << ", " << memory << "GB" << endl;
//
//
//}

ostream& operator<<(ostream& os, const MobilePhone& phone) {
    os << "Name: " << phone.name << "\n";
    os << "Brand: " << phone.brand << "\n";
    os << "Price: " << phone.price << "\n";
    os << "Color: " << phone.color << "\n";
    os << "Memory: " << phone.memory << " GB\n";
    return os;
}

istream& operator>>(istream& is, MobilePhone& phone) {
   is >> phone.name >> phone.brand >> phone.price >> phone.color >> phone.memory;
    return is;
}