#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
using namespace std;

class Address {
private:
    string index, city, street;
public:
    Address() : index(""), city(""), street("") {}
    Address(string index, string city, string street)
        : index(index), city(city), street(street) {
    }

    bool operator==(const Address& address) const {
        return index == address.index && city == address.city && street == address.street;
    }

    string getIndex() const { return index; }
    string getCity() const { return city; }
    string getStreet() const { return street; }

    friend istream& operator>>(istream& is, Address& address) {
        is >> address.index >> address.city >> address.street;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Address& address) {
        os << address.index << " " << address.city << " " << address.street;
        return os;
    }
};

#endif