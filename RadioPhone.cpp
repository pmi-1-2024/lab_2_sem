#include "RadioPhone.h"

RadioPhone::RadioPhone(string n, string b, double p, double r, bool a)
    : Phone(n, b, p), range(r), hasAnsweringMachine(a) {}

void RadioPhone::print(ostream& out) const {
    out << brand << " " << name << " " << price << " " << range << " " << (hasAnsweringMachine ? "Yes" : "No");
}

bool RadioPhone::hasAutoAnswer() const {
    return hasAnsweringMachine;
}