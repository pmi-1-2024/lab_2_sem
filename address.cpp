#include "Address.h"

Address::Address() : index(""), city(""), street("") {}

Address::Address(const string& index, const string& city, const string& street)
    : index(index), city(city), street(street) {}

Address::Address(const Address& other)
    : index(other.index), city(other.city), street(other.street) {}

Address& Address::operator=(const Address& other) {
    if (this != &other) {
        index = other.index;
        city = other.city;
        street = other.street;
    }
    return *this;
}

string Address::getIndex() const { return index; }
string Address::getCity() const { return city; }
string Address::getStreet() const { return street; }

ostream& operator<<(ostream& os, const Address& address) {
    os << address.index << ", " << address.city << ", " << address.street;
    return os;
}

istream& operator>>(istream& is, Address& address) {
    is >> address.index >> address.city >> address.street;
    return is;
}

