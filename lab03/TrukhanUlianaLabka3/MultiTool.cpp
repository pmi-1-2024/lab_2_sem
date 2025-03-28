#include "MultiTool.h"

MultiTool::MultiTool() : VacuumCleaner(), WashingMachine(), Combine() {}

string MultiTool::getName() const { return name; }
string MultiTool::getFirm() const { return firm; }
double MultiTool::getPrice() const { return price; }

bool MultiTool::operator<(const HouseElectronic& other) const {
	return this->getName() < other.getName();
}

void MultiTool::readData(istream& is) {
	is >> name >> firm >> price >> power1 >> color 
		>> programNum >> volume >> power2 >> funcNum;
}

void MultiTool::print(ostream& os) const {
	os << name << " " << firm << " " << price << " " << power1 << " " << color 
		<< " " << programNum << " " << volume << " " << power2 << " " << funcNum;
}

bool MultiTool::matchesCriteria(int searchType, const string& searchValue) const {
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

bool MultiTool::matchesCriteriaNum(int searchType, const size_t& searchValueNum) const {
	switch (searchType) {
	case 3:
		return price == searchValueNum;
	case 4:
		return power1 == searchValueNum;
	case 6:
		return programNum == searchValueNum;
	case 7:
		return volume == searchValueNum;
	case 8:
		return power2 == searchValueNum;
	case 9:
		return funcNum == searchValueNum;
	default:
		return false;
	}
}