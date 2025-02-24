#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
using namespace std;

class Address {
private:
    string index, city, street;
public:
    Address();
    Address(string index, string city, string street);

    bool operator==(const Address& address) const;

    string getIndex() const;
    string getCity() const;
    string getStreet() const;

    friend istream& operator>>(istream& is, Address& address);
    friend ostream& operator<<(ostream& os, const Address& address);

};
#endif 
