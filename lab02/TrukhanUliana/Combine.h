#ifndef COMBINE_H
#define COMBINE_H
#include <iostream>
#include <string>
#include "HouseElectronic.h"
using namespace std;

class Combine : public HouseElectronic
{
private:
	int power;
	int funcNum;
public:
	Combine();
	Combine(string n, string f, double p, int pow, int fn);
	Combine(const Combine& c);

	void readData(istream& is) override;

	friend istream& operator>>(istream& is, Combine& c);
	void print(ostream& os) const override;
	friend ostream& operator<<(ostream& os, Combine& c);
};
#endif
