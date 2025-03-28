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
    Address(const Address& other); 
    Address& operator=(const Address& other); 
    ~Address() = default; 

    string getIndex() const;
    string getCity() const;
    string getStreet() const;

    friend ostream& operator<<(ostream& os, const Address& address);
    friend istream& operator>>(istream& is, Address& address);
};

#endif 
