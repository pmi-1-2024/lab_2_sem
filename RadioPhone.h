#pragma once
#ifndef RADIOPHONE_H
#define RADIOPHONE_H

#include "Phone.h"

class RadioPhone : public Phone {
    double range;
    bool hasAnsweringMachine;
public:
    RadioPhone(string n, string b, double p, double r, bool a);
    void print(ostream& out) const override;
    bool hasAutoAnswer() const;
};

#endif // RADIOPHONE_Hñ