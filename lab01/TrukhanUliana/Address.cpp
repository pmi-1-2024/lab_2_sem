#include "Address.h"

Address::Address() : index(""), city(""), street("") {}

Address::Address(string index, string city, string street)
    : index(index), city(city), street(street) {
}

bool Address::operator==(const Address& address) const {
    return index == address.index && city == address.city && street == address.street;
}

string Address::getIndex() const { return index; }
string Address::getCity() const { return city; }
string Address::getStreet() const { return street; }

istream& operator>>(istream& is, Address& address) {
	is >> address.index >> address.city >> address.street;
	return is;
}

ostream& operator<<(ostream& os, const Address& address) {
	os << address.index << " " << address.city << " " << address.street;
	return os;
}
