#pragma once

#include "Electrodevice.h"
using namespace std;

class WashingMachine : virtual public Electrodevice {
protected:
    int programs;
    int volume;
public:
    WashingMachine();
    WashingMachine(const string& b, int p, int pr, int v);

    void print(ostream& os) const override;
    void read(istream& is) override;

    int getPrograms() const;
    int getVolume() const;
};
