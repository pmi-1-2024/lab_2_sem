#include "VacuumCleaner.h"

VacuumCleaner::VacuumCleaner(string n, string b, double p, int pow, string col)
    : ElectroDevice(n, b, p), power(pow), color(col) {}
VacuumCleaner::~VacuumCleaner() {}


VacuumCleaner::VacuumCleaner(const VacuumCleaner& other) : ElectroDevice(other), power(other.power) {}

VacuumCleaner& VacuumCleaner::operator=(const VacuumCleaner& other) {
    if (this != &other) {
        ElectroDevice::operator=(other);
        power = other.power;
    }
    return *this;
}

void VacuumCleaner::print(ostream& os) const {
    ElectroDevice::print(os);
    os << ", Power: " << power << " BT, Color: " << color;
}

void VacuumCleaner::read(istream& is) {
    ElectroDevice::read(is);
    is >> power >> color;
}

ostream& operator<<(ostream& os, const VacuumCleaner& device)
{
    device.print(os);
    return os;
}

istream& operator>>(istream& is, VacuumCleaner& device)
{
    device.read(is);
    return is;
}
