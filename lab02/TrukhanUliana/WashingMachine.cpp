#include "WashingMachine.h"

WashingMachine::WashingMachine() : HouseElectronic(), programNum(0), volume(0) {}

WashingMachine::WashingMachine(string n, string f, double p, int pn, int vol)
	: HouseElectronic(n, f, p), programNum(pn), volume(vol) {}

WashingMachine::WashingMachine(const WashingMachine& wm) 
	: HouseElectronic(wm), programNum(wm.programNum), volume(wm.volume) {}

istream& operator>>(istream& is, WashingMachine& wm) {
	is >> wm.name >> wm.firm >> wm.price >> wm.programNum >> wm.volume;
	return is;
}

void WashingMachine::print(ostream& os) const {
	os << name << " " << firm << " " << price << " " << programNum << " " << volume;
}

