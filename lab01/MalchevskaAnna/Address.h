#pragma once
#include <iostream>
using namespace std;

class Address {
private:
    string city;
    string street;
    int houseNumber;
    int zipCode;

public:
    Address();
    Address(string city, string street, int houseNumber, int zipCode);

    string getCity() const;
    string getStreet() const;
    int getHouseNumber() const;
    int getZipCode() const;

    friend ostream& operator<<(ostream& os, const Address& address);
    friend istream& operator>>(istream& is, Address& address);
};