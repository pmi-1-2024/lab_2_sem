#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include "Phone.h"
using namespace std;

class MobilePhone : public Phone {
private:
    string color;
    int memory;

public:
    MobilePhone();
    MobilePhone(string n, string b, double p, string c, int m);
    void display() const override;

    friend ostream& operator<<(ostream& os, const MobilePhone& phone);

    friend istream& operator>>(istream& is, MobilePhone& phone);
};

#endif
