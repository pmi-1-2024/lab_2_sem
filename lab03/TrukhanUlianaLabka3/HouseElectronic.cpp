#include "HouseElectronic.h"

HouseElectronic::HouseElectronic() : price(0.0) {}

istream& operator>>(istream& is, HouseElectronic& he) {
	he.readData(is); 
	return is;
}

ostream& operator<<(ostream& os, const HouseElectronic& he) {
	he.print(os);
	return os;
}

