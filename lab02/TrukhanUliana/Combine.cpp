#include "Combine.h"

Combine::Combine() : HouseElectronic(), power(0), funcNum(0) {}

Combine::Combine(string n, string f, double p, int pow, int fn) 
	: HouseElectronic(n, f, p), power(pow), funcNum(fn) {}

Combine::Combine(const Combine& c) 
	: HouseElectronic(c), power(c.power), funcNum(c.funcNum) {}

void Combine::readData(istream& is) {
	is >> power >> funcNum;
}

istream& operator>>(istream& is, Combine& c) {
	is >> c.name >> c.firm >> c.price;
	c.readData(is);
	return is;
}

void Combine::print(ostream& os) const {
	os << name << " " << firm << " " << price << " " << power << " " << funcNum;
}

ostream& operator<<(ostream& os, Combine& c) {
	c.print(os);
	return os;
}
