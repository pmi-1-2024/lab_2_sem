#include "RadioPhone.h"
RadioPhone::RadioPhone(string name, string brand, double price, int range, bool answeringMachine) : Phone(name, brand, price), range(range), answeringMachine(answeringMachine) {}
void RadioPhone::print(ostream& os) const {
    os << "RadioPhone: " << name << " " << brand << " " << price << " " << range << " " << answeringMachine << endl;
}
void RadioPhone::read(istream& is) {
    is >> name >> brand >> price >> range >> answeringMachine;
}