#ifndef GASBILL_H
#define GASBILL_H
#include <iostream>
#include "Bill.h"
using namespace std;
class GasBill : public Bill
{
private:
	int persons;
public:
	void read(istream& is) override;
	void print(ostream& os) const override;
};
#endif
