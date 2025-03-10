#include "HouseElectronic.h"

HouseElectronic::HouseElectronic() : name(" "), firm(" "), price(0) {}
HouseElectronic::HouseElectronic(string n, string f, double p) : name(n), firm(f), price(p) {}
HouseElectronic::HouseElectronic(const HouseElectronic& he) :name(he.name), firm(he.firm), price(he.price) {}

string HouseElectronic::getName() const { return name; }
string HouseElectronic::getFirm() const { return firm; }
double HouseElectronic::getPrice() const { return price; }

bool HouseElectronic::operator<(const HouseElectronic& other) const {
	return this->getName() < other.getName();
}


istream& operator>>(istream& is, HouseElectronic& he) {
	is >> he.name >> he.firm >> he.price;
	he.readData(is);
	return is;
}

void HouseElectronic::print(ostream& os) const {
	os << name << " " << firm << " " << price;
}

ostream& operator<<(ostream& os, const HouseElectronic& he) {
	he.print(os);
	return os;
}

