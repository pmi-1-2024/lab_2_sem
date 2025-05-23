#include "HybridPhone.h"

HybridPhone::HybridPhone() {}

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
