#include "Vacuumcleaner.h"


Vacuumcleaner::Vacuumcleaner() :Electroprilad(), power(0), color("nocolor") {}

Vacuumcleaner::Vacuumcleaner(string n, string f, int pr, int p, string c) : Electroprilad(n, f, pr), power(p), color(c) {}

Vacuumcleaner::Vacuumcleaner(const Vacuumcleaner& vac) :Electroprilad(vac), power(vac.power), color(vac.color) {}


void Vacuumcleaner::print(ostream& os) const
{

	os << "\nName: " << name;
	os << "\nFirm: " << firm;
	os << "\nPrice: " << price;
	os << "\nPower: " << power;
	os << "\nColor: " << color;
}

void Vacuumcleaner::write(istream& is)
{
	is >> power;
	is >> color;
}

istream& operator>>(istream& is, Vacuumcleaner& vac)
{
	is >> vac.name;
	is >> vac.firm;
	is >> vac.price;
	vac.write(is);
	return is;
}

ostream& operator<<(ostream& os, const Vacuumcleaner& vac)
{
	vac.print(os);
	return os;
}

