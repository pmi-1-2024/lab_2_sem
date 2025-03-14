#include "VacuumCleaner.h"

VacuumCleaner::VacuumCleaner() : HouseElectronic(), power1(0), color(" ") {}

VacuumCleaner::VacuumCleaner(string n, string f, double p, int pow, string col)
	: HouseElectronic(), power1(pow), color(col) {
	name = n; firm = f; price = p;
}

VacuumCleaner::VacuumCleaner(const VacuumCleaner& vc)
	: HouseElectronic(vc), power1(vc.power1), color(vc.color) {
}

string VacuumCleaner::getName() const { return name; }
string VacuumCleaner::getFirm() const { return firm; }
double VacuumCleaner::getPrice() const { return price; }

bool VacuumCleaner::operator<(const HouseElectronic& other) const {
	return this->getName() < other.getName();
}

void VacuumCleaner::readData(istream& is) {
	is >> name >> firm >> price >> power1 >> color;
}

void VacuumCleaner::print(ostream& os) const {
	os << name << " " << firm << " " << price << " " << power1 << " " << color;
}

bool VacuumCleaner::matchesCriteria(int searchType, const string& searchValue) const {
	switch (searchType) {
	case 1:
		return name == searchValue;
	case 2:
		return firm == searchValue;
	case 5:
		return color == searchValue;
	default:
		return false;
	}
}

bool VacuumCleaner::matchesCriteriaNum(int searchType, const size_t& searchValueNum) const {
	switch (searchType) {
	case 3: 
		return price == searchValueNum;
	case 4: 
		return power1 == searchValueNum;
	default:
		return false;
	}
}

istream& operator>> (istream& is, VacuumCleaner& vc) {
	is >> vc.name >> vc.firm >> vc.price;
	vc.readData(is);
	return is;
}

ostream& operator<<(ostream& os, VacuumCleaner& vc) {
	vc.print(os);
	return os;
}
