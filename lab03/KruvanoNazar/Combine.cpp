#include "Combine.h"

Combine::Combine():Electroprilad(),cpower(0),countf(0){}

Combine::Combine(string n, string f, int p, int cp, int cou):Electroprilad(n,f,p),cpower(cp),countf(cou){}

Combine::Combine(const Combine& com) :Electroprilad(com), cpower(com.cpower), countf(com.countf) {}

int Combine::GetCombinePower() const
{
	return cpower;
}

int Combine::GetCountOfFunctions() const
{
	return countf;
}

void Combine::print(ostream& os) const
{
	os << "\nName: " << name;
	os << "\nFirm: " << firm;
	os << "\nPrice: " << price;
	os << "\nPower: " << cpower;
	os << "\nCount of functions: " << countf;
}

void Combine::read(istream& is)
{
	is >> cpower;
	is >> countf;
}

istream& operator>>(istream& is, Combine& com)
{
	is >> com.name;
	is >> com.firm;
	is >> com.price;
	com.read(is);
	return is;
}

ostream& operator<<(ostream& os, const Combine& com)
{
	com.print(os);
	return os;
}
