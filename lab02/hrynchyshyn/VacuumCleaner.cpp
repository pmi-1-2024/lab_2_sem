#include "VacuumCleaner.h"

VacuumCleaner::VacuumCleaner() : power(0), color("") {}
VacuumCleaner::VacuumCleaner(const string& b, int p, int pow, const string& c)
    : Electrodevice(b, p), power(pow), color(c) {
}

void VacuumCleaner::print(ostream& os) const {
    os << "1 Name: Vacuum Cleaner\nBrand: " << brand << "\nPrice: " << price
        << "\nPower: " << power << "\nColor: " << color << "\n";
}

void VacuumCleaner::read(istream& is) {
    is >> brand >> price >> power >> color;
}
