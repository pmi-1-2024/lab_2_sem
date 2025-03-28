#ifndef VACUUMCLEANER_H
#define	VACUUMCLEANER_H
#include "HouseElectronic.h"

class VacuumCleaner : virtual public HouseElectronic
{
protected:
	int power1;
	string color;
public:
	VacuumCleaner();
	VacuumCleaner(string n, string f, double p, int pow, string col);
	VacuumCleaner(const VacuumCleaner& vc);

	string getName() const override;
	string getFirm() const override;
	double getPrice() const override;
	
	bool operator<(const HouseElectronic& other) const override;
	void readData(istream& is) override;
	void print(ostream& os) const override;
	bool matchesCriteria(int searchType, const string& searchValue) const override;
	bool matchesCriteriaNum(int searchType, const size_t& searchValueNum) const override;

	friend istream& operator>>(istream& is, VacuumCleaner& vc);
	friend ostream& operator<<(ostream& os, VacuumCleaner& vc);

};
#endif
