#ifndef WATERBILL_H
#define WATERBILL_H
#include <iostream>
#include "Bill.h"
using namespace std;

class WaterBill : public Bill
{
private:
	string surname;
	int lastdisplay;
	double paidvolume;
	double amountpaid;
public:
	double GetAmPaid()const override;
	string GetSurname() const override;
	void read(istream& is) override;
	void print(ostream& os) const override;
};
#endif
