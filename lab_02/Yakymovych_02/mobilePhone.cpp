#include "MobilePhone.h"
MobilePhone::MobilePhone(string name, string brand, double price, string color, int memory) : Phone(name, brand, price), color(color), memory(memory) {}
void MobilePhone::print(ostream& os) const {
    os << "MobilePhone: " << name << " " << brand << " " << price << " " << color << " " << memory << endl;
}
void MobilePhone::read(istream& is) {
    is >> name >> brand >> price >> color >> memory;
}