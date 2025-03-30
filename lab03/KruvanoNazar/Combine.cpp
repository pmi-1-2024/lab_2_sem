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
	Electroprilad::read(is);
	is >> cpower;
	is >> countf;
}
