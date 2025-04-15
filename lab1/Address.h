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
    Address(string ind, string cit, string str);

    friend istream& operator>>(istream& in, Address& addr);
    friend ostream& operator<<(ostream& out, const Address& addr);

    string GetCity() const;
    string GetIndex() const;
    string GetStreet() const;
};

#endif
