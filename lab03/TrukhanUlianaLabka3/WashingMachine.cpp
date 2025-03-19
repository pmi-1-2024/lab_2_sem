#include "WashingMachine.h"

WashingMachine::WashingMachine() : HouseElectronic(), programNum(0), volume(0) {}

WashingMachine::WashingMachine(string n, string f, double p, int pn, int vol)
	: HouseElectronic(), programNum(pn), volume(vol) {
	name = n; firm = f; price = p;
}

WashingMachine::WashingMachine(const WashingMachine& wm)
	: HouseElectronic(wm), programNum(wm.programNum), volume(wm.volume) {
}

string WashingMachine::getName()const { return name; }
string WashingMachine::getFirm() const { return firm; }
double WashingMachine::getPrice() const { return price; }

bool WashingMachine::operator<(const HouseElectronic& other) const {
	return this->getName() < other.getName();
}

void WashingMachine::readData(istream& is) {
	is >> name >> firm >> price >> programNum >> volume;
}

void WashingMachine::print(ostream& os) const {
	os << name << " " << firm << " " << price << " " << programNum << " " << volume;
}

bool WashingMachine::matchesCriteria(int searchType, const string& searchValue) const {
	switch (searchType) {
	case 1:
		return name == searchValue;
	case 2:
		return firm == searchValue;
	default:
		return false;
	}
}

bool WashingMachine::matchesCriteriaNum(int searchType, const size_t& searchValueNum) const {
	switch (searchType) {
	case 3:
		return price == searchValueNum;
	case 6:
		return programNum == searchValueNum;
	case 7:
		return volume == searchValueNum;
	default:
		return false;
	}
}

istream& operator>>(istream& is, WashingMachine& wm) {
	is >> wm.name >> wm.firm >> wm.price;
	wm.readData(is);
	return is;
}

ostream& operator<<(ostream& os, WashingMachine& wm) {
	wm.print(os);
	return os;
}
