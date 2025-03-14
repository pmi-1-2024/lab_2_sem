#ifndef RADIOPHONE_H
#define RADIOPHONE_H

#include "Phone.h"

class RadioPhone : public Phone {
private:
    double range;
    bool answeringMachine;

public:
    RadioPhone(string n, string b, double p, double r, bool a);
    void display() const override;
    bool hasAnsweringMachine() const override;
};

#endif
