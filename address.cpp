#include "Address.h"

Address::Address() : index(""), city(""), street("") {}

Address::Address(const string& index, const string& city, const string& street)
    : index(index), city(city), street(street) {}

string Address::getCity() const {
    return city;
}

ostream& operator<<(ostream& os, const Address& address) {
    os << address.index << ", " << address.city << ", " << address.street;
    return os;
}

istream& operator>>(istream& is, Address& address) {
    is >> address.index >> address.city >> address.street;
    return is;
}
