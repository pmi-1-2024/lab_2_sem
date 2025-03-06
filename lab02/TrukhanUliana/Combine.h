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

	friend istream& operator>>(istream& is, Combine& c);
	void print(ostream& os) const override;
};
#endif