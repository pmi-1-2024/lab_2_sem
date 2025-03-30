#include "Vacuumcleaner.h"


Vacuumcleaner::Vacuumcleaner() :Electroprilad(), power(0), color("nocolor") {}

Vacuumcleaner::Vacuumcleaner(string n, string f, int pr, int p, string c) : Electroprilad(n, f, pr), power(p), color(c) {}

Vacuumcleaner::Vacuumcleaner(const Vacuumcleaner& vac) :Electroprilad(vac), power(vac.power), color(vac.color) {}

int Vacuumcleaner::Getpower() const
{
	return power;
}

string Vacuumcleaner::GetColor() const
{
	return color;
}


void Vacuumcleaner::print(ostream& os) const
{

	os << "\nName: " << name;
	os << "\nFirm: " << firm;
	os << "\nPrice: " << price;
	os << "\nPower: " << power;
	os << "\nColor: " << color;
}

void Vacuumcleaner::read(istream& is)
{
	Electroprilad::read(is);
	is >> power;
	is >> color;
}
