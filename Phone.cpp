#include "Phone.h"

void MobilePhone::read(istream& in) {
    in >> name >> brand >> price >> color >> memory;
}

void MobilePhone::write(ostream& out) const {
    out << "MobilePhone: " << name << " " << brand << " " << price
        << " " << color << " " << memory << endl;
}

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

void HybridPhone::read(istream& in) {
    in >> name >> brand >> price;
    MobilePhone::read(in);
    RadioPhone::read(in);
}

void HybridPhone::write(ostream& out) const {
    out << "HybridPhone: " << name << " " << brand << " " << price << " ";
    MobilePhone::write(out);
    RadioPhone::write(out);
}
