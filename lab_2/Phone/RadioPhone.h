#ifndef RADIOPHONE_H
#define RADIOPHONE_H

#include "Phone.h"

class RadioPhone : public Phone {
public:
    double range;
    bool hasAnsweringMachine;

    RadioPhone();
    RadioPhone(const string& name, const string& brand, double price, double range, bool hasAnsweringMachine);

    double getRange() const;
    bool getHasAnsweringMachine() const;


    friend istream& operator>>(istream& is, RadioPhone& phone);
    friend ostream& operator<<(ostream& os, const RadioPhone& phone);
};

#endif
