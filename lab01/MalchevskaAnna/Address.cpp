#include "Address.h"

Address::Address() : city(""), street(""), houseNumber(0), zipCode(0) {}

Address::Address(string city, string street, int houseNumber, int zipCode)
    : city(city), street(street), houseNumber(houseNumber), zipCode(zipCode) {}

string Address::getCity() const { return city; }
string Address::getStreet() const { return street; }
int Address::getHouseNumber() const { return houseNumber; }
int Address::getZipCode() const { return zipCode; }

ostream& operator<<(ostream& os, const Address& address) {
    os << "City: " << address.city << ", Street: " << address.street
        << ", House Number: " << address.houseNumber << ", Zip Code: " << address.zipCode;
    return os;
}

istream& operator>>(istream& is, Address& address) {
    cout << "Enter city: ";
    is >> address.city;
    cout << "Enter street: ";
    is >> address.street;
    cout << "Enter house number: ";
    is >> address.houseNumber;
    cout << "Enter zip code: ";
    is >> address.zipCode;
    return is;
}