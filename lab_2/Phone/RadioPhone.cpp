#include "RadioPhone.h"

RadioPhone::RadioPhone() : Phone("", "", 0), range(0), hasAnsweringMachine(false) {}
RadioPhone::RadioPhone(const string& name, const string& brand, double price, double range, bool hasAnsweringMachine)
    : Phone(name, brand, price), range(range), hasAnsweringMachine(hasAnsweringMachine) {
}

double RadioPhone::getRange() const { return range; }
bool RadioPhone::getHasAnsweringMachine() const { return hasAnsweringMachine; }

istream& operator>>(istream& is, RadioPhone& phone) {
    is >> phone.name >> phone.brand >> phone.price >> phone.range >> phone.hasAnsweringMachine;
    return is;
}
ostream& operator<<(ostream& os, const RadioPhone& phone) {
    os << phone.name << " " << phone.brand << " " << phone.price << " " << phone.range << " "
        << (phone.hasAnsweringMachine ? "Yes" : "No");
    return os;
}
