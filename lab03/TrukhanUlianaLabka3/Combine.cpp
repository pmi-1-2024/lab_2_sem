#include "Combine.h"

Combine::Combine() : HouseElectronic(), power2(0), funcNum(0) {}

Combine::Combine(string n, string f, double p, int pow, int fn)
	: HouseElectronic(), power2(pow), funcNum(fn) {
	name = n; firm = f; price = p;
}

Combine::Combine(const Combine& c)
	: HouseElectronic(c), power2(c.power2), funcNum(c.funcNum) {
}

string Combine::getName()const { return name; }
string Combine::getFirm() const { return firm; }
double Combine::getPrice() const { return price; }

bool Combine::operator<(const HouseElectronic& other) const {
	return this->getName() < other.getName();
}

void Combine::readData(istream& is) {
	is >> name >> firm >> price >> power2 >> funcNum;
}

void Combine::print(ostream& os) const {
	os << name << " " << firm << " " << price << " " << power2 << " " << funcNum;
}

bool Combine::matchesCriteria(int searchType, const string& searchValue) const {
	switch (searchType) {
	case 1:
		return name == searchValue;
	case 2:
		return firm == searchValue;
	default:
		return false;
	}
}

bool Combine::matchesCriteriaNum(int searchType, const size_t& searchValueNum) const {
	switch (searchType) {
	case 3:
		return price == searchValueNum;
	case 8:
		return power2 == searchValueNum;
	case 9:
		return funcNum == searchValueNum;
	default:
		return false;
	}
}

istream& operator>>(istream& is, Combine& c) {
	is >> c.name >> c.firm >> c.price;
	c.readData(is);
	return is;
}

ostream& operator<<(ostream& os, Combine& c) {
	c.print(os);
	return os;
}
