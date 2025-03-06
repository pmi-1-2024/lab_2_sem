#ifndef HOUSEELECTRONIC_H
#define	HOUSEELECTRONIC_H
#include <iostream>
#include <string>
using namespace std;

class HouseElectronic
{
protected:
	string name;
	string firm;
	double price;

public:
	HouseElectronic();
	HouseElectronic(string n, string f, double p);
	HouseElectronic(const HouseElectronic& he);

	virtual ~HouseElectronic() {}

	string getName() const;
	string getFirm() const;
	double getPrice() const;

	friend istream& operator>>(istream& is, HouseElectronic& he);
	virtual void print(ostream& os) const;
	friend ostream& operator<<(ostream& os, const HouseElectronic& obj);
};
#endif 