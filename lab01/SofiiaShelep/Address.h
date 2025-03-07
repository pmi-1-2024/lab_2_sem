#pragma once
#include <string>
using namespace std;

class Address
{
private:
    string city;
    string street;
    int house;

public:
    Address();
    Address(string c, string s, int h);

    void setCity(string c);
    void setStreet(string s);
    void setHouse(int h);

    string getCity() const;
    string getStreet() const;
    int getHouse() const;

    friend ostream& operator<<(ostream& os, const Address& addr);
    friend istream& operator>>(istream& is, Address& addr);
};