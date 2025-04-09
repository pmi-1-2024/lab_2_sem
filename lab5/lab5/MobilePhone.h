#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include <iostream>
#include <string>

using namespace std;

struct MobilePhone {
    string name;
    string brand;
    double price;
    string color;
    int memory;

    friend ostream& operator<<(ostream& os, const MobilePhone& phone) {
        os << phone.name << " " << phone.brand << " $" << phone.price
            << " " << phone.color << " " << phone.memory << "GB";
        return os;
    }
};

bool compareByPrice(const MobilePhone& a, const MobilePhone& b);

bool compareByBrand(const MobilePhone& a, const MobilePhone& b);

#endif
