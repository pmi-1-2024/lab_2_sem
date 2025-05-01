#ifndef GASBILL_H
#define GASBILL_H
#include <iostream>
#include "Bill.h"
using namespace std;
class GasBill : public Bill
{
private:
	string surname;
	int persons;
	double amount_paid;
public:
	double GetAmPaid()const override;
	string GetSurname()const override;
	void read(istream& is) override;
	void print(ostream& os) const override;
};
#endif
