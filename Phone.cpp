#include "Phone.h"

Phone::Phone() { name = ""; brand = ""; price = 0; }
Phone::~Phone() {}

double Phone::getPrice() { return price; }
string Phone::getName() { return name; }

bool Phone::operator<(const Phone& other) const {
	return price < other.price;
}
