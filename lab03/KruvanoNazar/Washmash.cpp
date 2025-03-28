#include "Washmash.h"

Washmash::Washmash():Electroprilad(),countop(0),capacity(0){}

Washmash::Washmash(string n, string f, int pr, int cou, int cap):Electroprilad(n,f,pr),countop(cou),capacity(cap){}

Washmash::Washmash(const Washmash& wash):Electroprilad(wash),countop(wash.countop),capacity(wash.capacity){}

int Washmash::GetCountOfPrograms()const
{
	return countop;
}

int Washmash::GetCapacity()const
{
	return capacity;
}

void Washmash::print(ostream& os) const
{
	os << "\nName: " << name;
	os << "\nFirm: " << firm;
	os << "\nPrice: " << price;
	os << "\nCount of programs: " << countop;
	os << "\nCapacity: " << capacity;
}

void Washmash::read(istream& is)
{
	is >> countop;
	is >> capacity;
}

istream& operator>>(istream& is, Washmash& wash)
{
	is >> wash.name;
	is >> wash.firm;
	is >> wash.price;
	wash.read(is);
	return is;
}

ostream& operator<<(ostream& os, const Washmash& wash)
{
	wash.print(os);
	return os;
}

