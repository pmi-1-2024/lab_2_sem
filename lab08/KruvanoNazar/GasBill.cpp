#include "GasBill.h"

double GasBill::GetAmPaid() const
{
	return amount_paid;
}

string GasBill::GetSurname() const
{
	return surname;
}

void GasBill::read(istream& is)
{
	is >> surname >> persons >> amount_paid;

}

void GasBill::print(ostream& os) const
{
	os << "\Surname: " << surname;
	os << "\nPersons: " << persons;
	os << "\nAmount paid: " << amount_paid;
}
