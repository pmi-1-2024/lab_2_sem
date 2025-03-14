#include "VacuumCleaner.h"

VacuumCleaner::VacuumCleaner(string n, string b, double p, int pow, string col)
    : ElectroDevice(n, b, p), power(pow), color(col) {}
VacuumCleaner::~VacuumCleaner() {}

void VacuumCleaner::print(ostream& os) const {
    ElectroDevice::print(os);
    os << ", Power: " << power << " BT, Color: " << color;
}

void VacuumCleaner::read(istream& is) {
    ElectroDevice::read(is);
    is >> power >> color;
}


