#include "RadioPhone.h"

RadioPhone::RadioPhone() : range(0), answeringMachine(false) {}

void RadioPhone::read(istream& in) {

    in >> name >> brand >> price >> range >> answeringMachine;
}

void RadioPhone::write(ostream& out) const {

    out << "RadioPhone: " << name << " " << brand << " " << price
        << " " << range << " " << (answeringMachine ? "Yes" : "No") << endl;
}

bool RadioPhone::hasAnsweringMachine() const {
    return answeringMachine;
}
