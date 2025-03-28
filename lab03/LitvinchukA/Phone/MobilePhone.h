#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include "Phone.h"

class MobilePhone : virtual public Phone {
public:
    string color;
    int memory;

    MobilePhone();
    MobilePhone(const string& name, const string& brand, double price, const string& color, int memory);

    string getColor() const;
    int getMemory() const;

    bool operator<(const Phone& other) const override;
    void input(istream& is) override;

    friend istream& operator>>(istream& is, MobilePhone& phone);
    friend ostream& operator<<(ostream& os, const MobilePhone& phone);
};

#endif