#include "Address.h"
#include <iostream>
using namespace std;

Address::Address():city(""), street(""), houseNumber(0), index(0){}

Address::Address(string city, string street, int houseNumber, int index)
    : index(index), city(city), streetHouse(streetHouse) {}

bool Address::operator==(const Address& address) const {
    return city == address.city && street == address.street &&
        houseNumber == address.houseNumber && index == address.index;
}

string Address::getCity() const { return city; }
string Address::getStreet() const { return street; }
int Address::getHouseNumber() const { return houseNumber; }
int Address::getIndex() const { return index; }

ostream& operator<<(ostream& os, const Address& addr) {
    os << addr.city << " " << addr.street << " " << addr.houseNumber << " " << addr.index;
    return os;
}

istream& operator>>(istream& is, Address& addr) {
    is >> ws;
    getline(is, addr.city);
    getline(is, addr.street);
    is >> addr.houseNumber >> addr.index;
    return is;
}