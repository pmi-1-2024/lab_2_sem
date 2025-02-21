#pragma once
#include <string>

using namespace std;

class Address {
public:
    string city;
    string street;
    int houseNumber;
    Address(string city = "", string street = "", int houseNumber = 0);
    void input();
    void output() const;
};
