#ifndef COMBINE_H
#define COMBINE_H
#include "HouseElectronic.h"

class Combine : virtual public HouseElectronic
{
protected:
	int power2;
	int funcNum;
public:
	Combine();
	Combine(string n, string f, double p, int pow, int fn);
	Combine(const Combine& c);

	string getName() const override;
	string getFirm() const override;
	double getPrice() const override;

	bool operator<(const HouseElectronic& other) const override;
	void readData(istream& is) override;
	void print(ostream& os) const override;
	bool matchesCriteria(int searchType, const string& searchValue) const override;
	bool matchesCriteriaNum(int searchType, const size_t& searchValueNum) const override;

	friend istream& operator>>(istream& is, Combine& c);
	friend ostream& operator<<(ostream& os, Combine& c);
};
#endif
