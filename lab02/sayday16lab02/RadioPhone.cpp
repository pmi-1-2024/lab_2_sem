#include "RadioPhone.h"

RadioPhone::RadioPhone(string n, string b, double p, double r, bool a) : Phone(n, b, p), range(r), answeringMachine(a) {}

void RadioPhone::display() const {
    cout << "Radio Phone: " << name << ", " << brand << ", " << price << ", Range: " << range << "m, Answering Machine: " << (answeringMachine ? "Yes" : "No") << endl;
}

bool RadioPhone::hasAnsweringMachine() const { return answeringMachine; }

ostream& operator<<(ostream& os, const RadioPhone& rp) {
    os << "Radio Phone: " << rp.name << ", " << rp.brand << ", "
        << rp.price << ", Range: " << rp.range
        << "m, Answering Machine: " << (rp.answeringMachine ? "Yes" : "No");
    return os;
}

istream& operator>>(istream& is, RadioPhone& rp) {
    is >> rp.name >> rp.brand >> rp.price >> rp.range >> rp.answeringMachine;
    return is;
}