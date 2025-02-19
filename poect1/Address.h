#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address {
private:
    int postIndex;
    string city;
    string street;

public:
    Address(int postIndex = 0, string city = "", string street = "");
    int getPostIndex() const;
    string getCity() const;
    string getStreet() const;
};

#endif


