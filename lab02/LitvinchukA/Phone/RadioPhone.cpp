#include "RadioPhone.h"

RadioPhone::RadioPhone() : Phone("", "", 0), range(0), answeringMachine(false) {}

RadioPhone::RadioPhone(const string& name, const string& brand, double price, double range, bool answeringMachine)
    : Phone(name, brand, price), range(range), answeringMachine(answeringMachine) {
}

double RadioPhone::getRange() const { return range; }

bool RadioPhone::hasAnsweringMachine() const { return answeringMachine; }

bool RadioPhone::operator<(const Phone& other) const {
    return price < other.getPrice();
}

void RadioPhone::input(istream& is) {
    is >> name >> brand >> price >> range >> answeringMachine;
}

void RadioPhone::read(istream& is) {
    input(is);
}

istream& operator>>(istream& is, RadioPhone& phone) {
    phone.input(is);
    return is;
}

ostream& operator<<(ostream& os, const RadioPhone& phone) {
    os << phone.name << " " << phone.brand << " " << phone.price << " " << phone.range << " "
        << (phone.answeringMachine ? "Yes" : "No");
    return os;
}