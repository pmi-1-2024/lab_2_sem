#include "MobilePhone.h"

MobilePhone::MobilePhone() : color(""), memory(0) {}

void MobilePhone::read(istream& in) {

    in >> name >> brand >> price >> color >> memory;
}

void MobilePhone::write(ostream& out) const {

    out << "MobilePhone: " << name << " " << brand << " " << price
        << " " << color << " " << memory << endl;
}
