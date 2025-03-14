#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>

using namespace std;

class Address {
private:
    string index;
    string city;
    string street;

public:
    Address();
    Address(const string& index, const string& city, const string& street);

    string getCity() const;

    friend ostream& operator<<(ostream& os, const Address& address);
    friend istream& operator>>(istream& is, Address& address);
};

#endif
