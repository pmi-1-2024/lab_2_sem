#include "HybridPhone.h"
HybridPhone::HybridPhone(string name, string brand, double price, string color, int memory, int range, bool answeringMachine)
    : Phone(name, brand, price), MobilePhone(name, brand, price, color, memory), RadioPhone(name, brand, price, range, answeringMachine) {}
void HybridPhone::print(ostream& os) const {
    os << "HybridPhone: " << name << " " << brand << " " << price << " " << color << " " << memory << " " << range << " " << answeringMachine << endl;
}
void HybridPhone::read(istream& is) {
    is >> name >> brand >> price >> color >> memory >> range >> answeringMachine;
}