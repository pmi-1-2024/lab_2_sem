#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include "Electrodevice.h"

class WashingMachine : public Electrodevice {
    int programs, volume;
public:
    WashingMachine();
    WashingMachine(const string& b, int p, int pr, int v);

    void print(ostream& os) const override;
    void read(istream& is) override;

    friend ostream& operator<<(ostream& os, const WashingMachine& device);
    friend istream& operator>>(istream& is, WashingMachine& device);
};

#endif