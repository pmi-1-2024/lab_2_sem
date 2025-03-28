#include "SuperRobot.h"

SuperRobot::SuperRobot() : Electroprilad(), Vacuumcleaner(), Washmash(), Combine(){}

SuperRobot::SuperRobot(string n, string f, int p, int pow, string col, int cop, int cap, int cp, int cof) : Electroprilad(n,f,p),Vacuumcleaner(n,f,p,pow,col),Washmash(n,f,p,cop,cap),Combine(n,f,p,cp,cof){}

SuperRobot::SuperRobot(const SuperRobot& sr) : Electroprilad(sr), Vacuumcleaner(sr), Washmash(sr), Combine(sr){}

void SuperRobot::print(ostream& os)const
{
	os << "\nName: " << name;
	os << "\nFirm: " << firm;
	os << "\nPrice: " << price;
	os << "\nPower of Vacuumcleaner: " << power;
	os << "\nColor of Vacuumcleaner: " << color;
	os << "\nCount of Washing machine programs: " << countop;
	os << "\nCapacity of Washing machine: " << capacity;
	os << "\nPower of Combine: " << cpower;
	os << "\nCount of Combine`s functions: " << countf;
}

void SuperRobot::read(istream& is)
{
	Vacuumcleaner::read(is);
	Washmash::read(is);
	Combine::read(is);
}

istream& operator>>(istream& is, SuperRobot& sr)
{
	is >> sr.name;
	is >> sr.firm;
	is >> sr.price;
	sr.read(is);
	return is;
}

ostream& operator<<(ostream& os, SuperRobot& sr)
{
	sr.print(os);
	return os;
}

