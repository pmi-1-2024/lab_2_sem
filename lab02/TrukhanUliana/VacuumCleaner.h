#ifndef VACUUMCLEANER_H
#define	VACUUMCLEANER_H

#include <iostream>
#include <string>
#include "HouseElectronic.h"
using namespace std;

class VacuumCleaner : public HouseElectronic
{
private:
	int power;
	string color;
public:
	VacuumCleaner();
	VacuumCleaner(string n, string f, double p, int pow, string col);
	VacuumCleaner(const VacuumCleaner& vc);

	void readData(istream& is) override;

	friend istream& operator>>(istream& is, VacuumCleaner& vc);
	void print(ostream& os) const override;
	friend ostream& operator<<(ostream& os, VacuumCleaner& vc);

};
#endif
