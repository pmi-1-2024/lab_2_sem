#include "Address.h"
using namespace std;

Address::Address() : zipcode(0), city(""), street("") {}
Address::Address(int code, const string& c, const string& s) : zipcode(code), city(c), street(s) {}

ostream& operator<<(ostream& os, const Address& a) {
    os << a.zipcode << " " << a.city << " " << a.street;
    return os;
}

istream& operator>>(istream& is, Address& a) {
    is >> a.zipcode >> ws;
    getline(is, a.city);
    getline(is, a.street);
    return is;
}