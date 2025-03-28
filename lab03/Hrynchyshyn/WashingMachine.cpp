#include "WashingMachine.h"

WashingMachine::WashingMachine() : Electrodevice(), programs(0), volume(0) {}

WashingMachine::WashingMachine(const string& b, int p, int pr, int v)
    : Electrodevice(b, p), programs(pr), volume(v) {
}

void WashingMachine::print(ostream& os) const {
    os << "Washing Machine\nBrand: " << brand << "\nPrice: " << price << "\nPrograms: " << programs << "\nVolume: " << volume << "\n";
}

void WashingMachine::read(istream& is) {
    Electrodevice::read(is);
    is >> programs >> volume;
}

int WashingMachine::getPrograms() const {
    return programs;
}

int WashingMachine::getVolume() const {
    return volume;
}