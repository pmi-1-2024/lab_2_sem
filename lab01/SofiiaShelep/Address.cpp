#include "Address.h"
#include <iostream>

Address::Address() : city(""), street(""), house(0) {}

Address::Address(string c, string s, int h) : city(c), street(s), house(h) {}

void Address::setCity(string c) { city = c; }
void Address::setStreet(string s) { street = s; }
void Address::setHouse(int h) { house = h; }

string Address::getCity() const { return city; }
string Address::getStreet() const { return street; }
int Address::getHouse() const { return house; }

ostream& operator<<(ostream& os, const Address& addr)
{
    os << addr.city << " " << addr.street << " " << addr.house;
    return os;
}

istream& operator>>(istream& is, Address& addr)
{
    is >> addr.city >> addr.street >> addr.house;
    return is;
}