#include "Phone.h"

Phone::Phone() {
	name = "";
	brand = "";
	price = 0;
}

Phone::~Phone() {}

void Phone::read(istream& in) {
	in >> name >> brand >> price;
}

void Phone::write(ostream& out) const {
	out << name << " " << brand << " $" << price << endl;
}

string Phone::getName() const { return name; }
string Phone::getBrand() const { return brand; }
double Phone::getPrice() const { return price; }
