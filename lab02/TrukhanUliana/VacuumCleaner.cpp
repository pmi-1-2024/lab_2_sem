#include "VacuumCleaner.h"

VacuumCleaner::VacuumCleaner() : HouseElectronic(), power(0), color(" ") {}

VacuumCleaner::VacuumCleaner(string n, string f, double p, int pow, string col)
	: HouseElectronic(n, f, p), power(pow), color(col) {}

VacuumCleaner::VacuumCleaner(const VacuumCleaner& vc)
	: HouseElectronic(vc), power(vc.power), color(vc.color) {}

void VacuumCleaner::readData(istream& is) {
	is >> power >> color;
}

istream& operator>> (istream& is, VacuumCleaner& vc) {
	is >> vc.name >> vc.firm >> vc.price;
	vc.readData(is);
	return is;
}

void VacuumCleaner::print(ostream& os) const {
	os << name << " " << firm << " " << price << " " << power << " " << color;
}

ostream& operator<<(ostream& os, VacuumCleaner& vc) {
	vc.print(os);
	return os;
}
