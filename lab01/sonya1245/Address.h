#pragma once
#include <iostream>
#include <string>

using namespace std;

class Address {
private:
    int index;
    string city;
    string street;

public:
    Address();
    friend istream& operator>>(istream& in, Address& address);
    friend ostream& operator<<(ostream& out, const Address& address);
    bool operator==(const Address& other) const;
    bool operator!=(const Address& other) const;
    const string& getCity() const;
};

