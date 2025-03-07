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

istream& Vacuumcleaner::write(istream& is)
{
	is >> name;
	is >> firm;
	is >> price;
	is >> power;
	is >> color;
	return is;
}

istream& operator>>(istream& is, Vacuumcleaner& vac)
{
	return vac.write(is);
}

ostream& operator<<(ostream& os, const Vacuumcleaner& vac)
{
	vac.print(os);
	return os;
}

