#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H
#include "HouseElectronic.h"

class WashingMachine : virtual public HouseElectronic
{
protected:
	int programNum;
	int volume;
public:
	WashingMachine();
	WashingMachine(string n, string f, double p, int pn, int vol);
	WashingMachine(const WashingMachine& wm);

	string getName() const override;
	string getFirm() const override;
	double getPrice() const override;

	bool operator<(const HouseElectronic& other) const override;
	void readData(istream& is) override;
	void print(ostream& os) const override;
	bool matchesCriteria(int searchType, const string& searchValue) const override;
	bool matchesCriteriaNum(int searchType, const size_t& searchValueNum) const override;

	friend istream& operator>>(istream& is, WashingMachine& wm);
	friend ostream& operator<<(ostream& os, WashingMachine& wm);
};
#endif
