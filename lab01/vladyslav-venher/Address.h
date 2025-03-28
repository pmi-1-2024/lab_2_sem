#pragma once
#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string zipcode;
    string city;
    string street;
public:
    Address();
    Address(string zipcode, string city, string street);
    string getZipcode() const;
    string getCity() const;
    string getStreet() const;
    bool operator==(const Address& address) const;
    friend ostream& operator<<(ostream& os, const Address& address);
    friend istream& operator>>(istream& is, Address& address);
};
