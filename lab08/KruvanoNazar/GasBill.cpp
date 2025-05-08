#include "GasBill.h"

void GasBill::read(istream& is)
{
	is >> surname >> amountpaid >> persons;

}

void GasBill::print(ostream& os) const
{
	os << "\Surname: " << surname;
	os << "\nPersons: " << persons;
	os << "\nAmount paid: " << amountpaid;
}
