#ifndef VACUUMCLEANER_H
#define VACUUMCLEANER_H

#include "Electrodevice.h"

class VacuumCleaner : public Electrodevice {
    int power;
    string color;
public:
    VacuumCleaner();
    VacuumCleaner(const string& b, int p, int pow, const string& c);

    void print(ostream& os) const override;
    void read(istream& is) override;

    friend ostream& operator<<(ostream& os, const VacuumCleaner& device);
    friend istream& operator>>(istream& is, VacuumCleaner& device);
};

#endif
