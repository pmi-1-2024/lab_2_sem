#ifndef WATERBILL_H
#define WATERBILL_H
#include <iostream>
#include "Bill.h"
using namespace std;

class WaterBill : public Bill
{
private:
	int lastdisplay;
	double paidvolume;
public:
	void read(istream& is) override;
	void print(ostream& os) const override;
};
#endif
