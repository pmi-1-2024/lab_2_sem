#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include "Phone.h"

class MobilePhone : public Phone {
public:
    string color;
    int memory;

    MobilePhone();
    MobilePhone(const string& name, const string& brand, double price, const string& color, int memory);

    string getColor() const;
    int getMemory() const;

    friend istream& operator>>(istream& is, MobilePhone& phone);
    friend ostream& operator<<(ostream& os, const MobilePhone& phone);
};

#endif
