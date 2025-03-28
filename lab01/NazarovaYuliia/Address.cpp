#include "Address.h"
#include <iostream>
using namespace std;

Address::Address():city(""), street(""), houseNumber(0), index(0){}

Address::Address(string city, string street, int houseNumber, int index)
    : city(city), street(street), houseNumber(houseNumber) index(index) {}

bool Address::operator==(const Address& address) const {
    return city == address.city && street == address.street &&
        houseNumber == address.houseNumber && index == address.index;
}

string Address::getCity() const { return city; }
string Address::getStreet() const { return street; }
int Address::getHouseNumber() const { return houseNumber; }
int Address::getIndex() const { return index; }

ostream& operator<<(ostream& os, const Address& addr) {
    os << "City: " << addr.city << "\n"
        << "Street: " << addr.street << "\n"
        << "House number: " << addr.houseNumber << "\n"
        << "Index: " << addr.index;
    return os;
}

istream& operator>>(istream& is, Address& addr) {
    cout << "Enter city: ";
    is >> ws;
    getline(is, addr.city);

    cout << "Enter street: ";
    is >> ws;
    getline(is, addr.street);
    cout << "Enter house number: ";
    is >> addr.houseNumber;

    cout << "Enter index: ";
    is >> addr.index;
    return is;
}