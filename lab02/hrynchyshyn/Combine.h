#ifndef COMBINE_H
#define COMBINE_H

#include "Electrodevice.h"

class Combine : public Electrodevice {
    int power, functions;
public:
    Combine();
    Combine(const string& b, int p, int pow, int f);

    void print(ostream& os) const override;
    void read(istream& is) override;

    friend ostream& operator<<(ostream& os, const Combine& device);
    friend istream& operator>>(istream& is, Combine& device);
};

#endif
