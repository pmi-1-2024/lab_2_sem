#pragma once

#include <string>
using namespace std;

class Address {
public:
    string city;
    string street;
    int houseNumber;
    int index;

    Address();
    Address(string city, string street, int houseNumber, int index);

    void input();
    void output() const;
};

