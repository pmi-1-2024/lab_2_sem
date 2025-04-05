#include "Address.h"

Address::Address() : index(""), city(""), street("") {}

Address::Address(string ind, string cit, string str) : index(ind), city(cit), street(str) {}

istream& operator>>(istream& in, Address& addr) {
    cout << "Enter index: ";
    in >> addr.index;
    cout << "Enter city: ";
    in >> addr.city;
    cout << "Enter street: ";
    in >> addr.street;
    return in;
}

ostream& operator<<(ostream& out, const Address& addr) {
    out << "Address: " << addr.index << ", " << addr.city << ", " << addr.street;
    return out;
}

string Address::GetCity() const { return city; }
string Address::GetIndex() const { return index; }
string Address::GetStreet() const { return street; }
