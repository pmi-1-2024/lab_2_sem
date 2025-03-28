#include "WashingMachine.h"

WashingMachine::WashingMachine(string n, string b, double p, int np, double vol)
    : ElectroDevice(n, b, p), numPrograms(np), volume(vol) {}

WashingMachine::~WashingMachine() { }

void WashingMachine::print(ostream& os) const {
    ElectroDevice::print(os);
    os << ", NumPrograms: " << numPrograms << ", Volume: " << volume << " ë";
}

void WashingMachine::read(istream& is) {
    ElectroDevice::read(is);
    is >> numPrograms >> volume;
}

ostream& operator<<(ostream& os, const WashingMachine& device)
{
    device.print(os);
    return os;
}

istream& operator>>(istream& is, WashingMachine& device)
{
    device.read(is);
    return is;
}
