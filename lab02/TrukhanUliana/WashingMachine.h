#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H
#include <iostream>
#include <string>
#include "HouseElectronic.h"
using namespace std;

class WashingMachine : public HouseElectronic
{
private:
	int programNum;
	int volume;
public:
	WashingMachine();
	WashingMachine(string n, string f, double p, int pn, int vol);
	WashingMachine(const WashingMachine& wm);

	void readData(istream& is) override;

	friend istream& operator>>(istream& is, WashingMachine& wm);
	void print(ostream& os) const override;
	friend ostream& operator<<(ostream& os, WashingMachine& wm);
};
#endif
