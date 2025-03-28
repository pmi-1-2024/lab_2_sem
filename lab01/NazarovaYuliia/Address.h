#pragma once
#include <string>
using namespace std;

class Address {
private:
    string city;
    string street;
    int houseNumber;
    int index;

public:
    Address();
    Address(string city, string street, int houseNumber, int index);

    bool operator==(const Address& address) const;

    string getCity() const;
    string getStreet() const;
    int getHouseNumber() const;
    int getIndex() const;

    friend ostream& operator<<(ostream& out, const Address& addr);
    friend istream& operator>>(istream& in, Address& addr);
};