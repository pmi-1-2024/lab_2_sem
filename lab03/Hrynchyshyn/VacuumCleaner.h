#pragma once

#include "Electrodevice.h"
using namespace std;
class VacuumCleaner : virtual public Electrodevice {
protected:
    int power;
    string color;
public:
    VacuumCleaner();
    VacuumCleaner(const string& b, int p, int pow, const string& c);

    void print(ostream& os) const override;
    void read(istream& is) override;

    int getPower() const;
    string getColor() const;
};