#include "Electroprilad.h"

Electroprilad::Electroprilad() : name("noname"), firm("nofirm"), price(0) {}

Electroprilad::Electroprilad(string n, string f, int p)
{
	name = n;
	firm = f;
	price = p;
}

Electroprilad::Electroprilad(const Electroprilad& elp)
{
	name = elp.name;
	firm = elp.firm;
	price = elp.price;
}

string Electroprilad::GetName() const
{
	return name;
}

string Electroprilad::GetFirm() const
{
	return firm;
}

int Electroprilad::GetPrice() const
{
	return price;
}

bool Electroprilad::operator<(const Electroprilad& elp) const
{
	return this->GetName() < elp.GetName();
}

void Electroprilad::print(ostream& os) const
{
	os << "\nName: " << name;
	os << "\nFirm: " << firm;
	os << "\nPrice: " << price;
}

istream& Electroprilad::write(istream& is)
{
	is >> name;
	is >> firm;
	is >> price;
	return is;
}

istream& operator>>(istream& is, Electroprilad& elp)
{
	return elp.write(is);
}

ostream& operator<<(ostream& os, const Electroprilad& elp)
{
	elp.print(os);
	return os;
}
