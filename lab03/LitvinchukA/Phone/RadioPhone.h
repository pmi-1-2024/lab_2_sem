#ifndef RADIOPHONE_H
#define RADIOPHONE_H

#include "Phone.h"

class RadioPhone : virtual public Phone {
protected:
    double range;
    bool answeringMachine;

public:
    RadioPhone();
    RadioPhone(const string& name, const string& brand, double price, double range, bool answeringMachine);

    double getRange() const;
    bool hasAnsweringMachine() const override;

    bool operator<(const Phone& other) const override;
    void input(istream& is) override;
    void read(istream& is) override;

    friend istream& operator>>(istream& is, RadioPhone& phone);
    friend ostream& operator<<(ostream& os, const RadioPhone& phone);
};

#endif