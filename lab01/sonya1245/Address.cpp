#include "Address.h"

Address::Address() : index(0), city(""), street("") {}

istream& operator>>(istream& in, Address& address) {
    cout << "Enter address index: ";
    in >> address.index;
    in.ignore();
    cout << "Enter city: ";
    getline(in, address.city);
    cout << "Enter street: ";
    getline(in, address.street);
    return in;
}

ostream& operator<<(ostream& out, const Address& address) {
    out << "Address: " << address.index << ", " << address.city << ", " << address.street;
    return out;
}

bool Address::operator==(const Address& other) const {
    return index == other.index && city == other.city && street == other.street;
}

bool Address::operator!=(const Address& other) const {
    return !(*this == other);
}

const string& Address::getCity() const {
    return city;
}