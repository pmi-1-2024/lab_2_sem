#include "VacuumCleaner.h"

VacuumCleaner::VacuumCleaner() : Electroprilad(), power(0), color("") {}

VacuumCleaner::VacuumCleaner(string n, string f, int p, int pw, string c)
    : Electroprilad(n, f, p), power(pw), color(c) {}

VacuumCleaner::VacuumCleaner(const VacuumCleaner& vc)
    : Electroprilad(vc), power(vc.power), color(vc.color) {}

void VacuumCleaner::print(ostream& os) const {
    Electroprilad::print(os);
    os << "Power: " << power << ", Color: " << color << endl;
}

void VacuumCleaner::write(istream& is) {
    is >> name >> firm >> price >> power >> color;
}
