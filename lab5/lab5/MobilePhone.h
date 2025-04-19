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

    string getBrand() const { return brand; }
    double getPrice() const { return price; }

    bool operator<(const MobilePhone& other) const {
        if (brand == other.brand)
            return price < other.price;
        return brand < other.brand;
    }

    friend ostream& operator<<(ostream& os, const MobilePhone& phone) {
        os << phone.name << " " << phone.brand << " $" << phone.price
            << " " << phone.color << " " << phone.memory << "GB";
        return os;
    }

    friend istream& operator>>(istream& is, MobilePhone& phone) {
        is >> phone.name >> phone.brand >> phone.price >> phone.color >> phone.memory;
        return is;
    }
};

//

bool compareByPrice(const MobilePhone& a, const MobilePhone& b);

bool compareByBrand(const MobilePhone& a, const MobilePhone& b);

#endif
