#pragma once
#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include "Phone.h"

class MobilePhone : public Phone {
    string color;
    int memory;
public:
    MobilePhone(string n, string b, double p, string c, int m);
    void print(ostream& out) const override;
};

#endif // MOBILEPHONE_H