#include "WaterBill.h"

void WaterBill::read(istream& is)
{
	is >> surname >> amountpaid >> lastdisplay >> paidvolume;
}

void WaterBill::print(ostream& os) const
{
	os << "\Surname: " << surname;
	os << "\nLast counter display: " << lastdisplay;
	os << "\nPaid volume: " << paidvolume;
	os << "\nAmount paid: " << amountpaid;
}
