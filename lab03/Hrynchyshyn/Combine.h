#pragma once

#include "Electrodevice.h"

class Combine : virtual public Electrodevice {
protected:
    int power, functions;
public:
    Combine();
    Combine(const string& b, int p, int pow, int f);

    void print(ostream& os) const override;
    void read(istream& is) override;

    int getCombinePower() const;
    int getFunctions() const;
};

