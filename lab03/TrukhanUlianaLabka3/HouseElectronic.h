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
	virtual ~HouseElectronic() {}

	virtual string getName() const = 0;
	virtual string getFirm() const = 0;
	virtual double getPrice() const = 0;

	virtual bool operator<(const HouseElectronic& other) const = 0;
	virtual void readData(istream& is) = 0;
	virtual void print(ostream& os) const = 0;
	virtual bool matchesCriteria(int searchType, const string& searchValue) const = 0;
	virtual bool matchesCriteriaNum(int searchType, const size_t& searchValueNum) const = 0;
	
	friend istream& operator>>(istream& is, HouseElectronic& he);
	friend ostream& operator<<(ostream& os, const HouseElectronic& obj);
};
#endif 