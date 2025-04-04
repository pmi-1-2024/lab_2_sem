#include "WashingMachine.h"

WashingMachine::WashingMachine() : programs(0), volume(0) {}
WashingMachine::WashingMachine(const string& b, int p, int pr, int v)
    : Electrodevice(b, p), programs(pr), volume(v) {
}

void WashingMachine::print(ostream& os) const {
    os << "2 Name: Washing Machine\nBrand: " << brand << "\nPrice: " << price
        << "\nPrograms: " << programs << "\nVolume: " << volume << "\n";
}

void WashingMachine::read(istream& is) {
    is >> brand >> price >> programs >> volume;
}

ostream& operator<<(ostream& os, const WashingMachine& device) {
    device.print(os);
    return os;
}

istream& operator>>(istream& is, WashingMachine& device) {
    device.read(is);
    return is;
}