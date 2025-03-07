#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include "Phone.h"

class MobilePhone : public Phone {
private:
    string color;
    int memory;

public:
    MobilePhone(string n, string b, double p, string c, int m);
    void display() const override;
};

#endif 


