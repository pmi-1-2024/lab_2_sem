#include "Address.h"
using namespace std;

Address::Address() : zipcode(""), city(""), street("") {}

Address::Address(string zipcode, string city, string street) : zipcode(zipcode), city(city), street(street) {}

string Address::getZipcode() const { return zipcode; }
string Address::getCity() const { return city; }
string Address::getStreet() const { return street; }



bool Address::operator==(const Address& address) const {
    return zipcode == address.zipcode && city == address.city && street == address.street;
}

ostream& operator<<(ostream& os, const Address& address) {
    os << address.zipcode << " " << address.city << " " << address.street;
    return os;
}

istream& operator>>(istream& is, Address& address) {
    is >> address.zipcode >> address.city >> address.street;
    return is;
}