#ifndef MULTITOOL_H
#define	MULTITOOL_H
#include "Utils.h"
class MultiTool : public VacuumCleaner, public WashingMachine, public Combine
{
public:
	MultiTool();

	string getName() const override;
	string getFirm() const override;
	double getPrice() const override;

	bool operator<(const HouseElectronic& other) const override;
	void readData(istream& is) override;
	void print(ostream& os) const override;
	bool matchesCriteria(int searchType, const string& searchValue) const override;
	bool matchesCriteriaNum(int searchType, const size_t& searchValueNum) const override;
};


#endif 