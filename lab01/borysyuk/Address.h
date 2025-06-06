#pragma once
#include <iostream>
#include <string>

using namespace std;

class Address {
private:
    string index, city, street;
public:
    Address();
    Address(string i, string c, string s);
    string getCity() const;
    string getFullAddress() const;
    void display(ostream& os) const;
    void read(istream& is);
    friend istream& operator>>(istream& is, Address& a);
    friend ostream& operator<<(ostream& os, Address& a);
};
