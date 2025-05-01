#include "WaterBill.h"

double WaterBill::GetAmPaid() const
{
	return amountpaid;
}

string WaterBill::GetSurname() const
{
	return surname;
}

void WaterBill::read(istream& is)
{
	is >> surname >> lastdisplay >> paidvolume >> amountpaid;
}

void WaterBill::print(ostream& os) const
{
	os << "\Surname: " << surname;
	os << "\nLast counter display: " << lastdisplay;
	os << "\nPaid volume: " << paidvolume;
	os << "\nAmount paid: " << amountpaid;
}
