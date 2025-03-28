#ifndef HYBRIDPHONE_H
#define HYBRIDPHONE_H

#include "MobilePhone.h"
#include "RadioPhone.h"

class HybridPhone : public MobilePhone, public RadioPhone {
public:
    HybridPhone();
    HybridPhone(const string& name, const string& brand, double price, const string& color, int memory, double range, bool hasAnsweringMachine);

    bool hasAnsweringMachine() const override;
    bool operator<(const Phone& other) const override;
    void input(istream& is) override;

    friend istream& operator>>(istream& is, HybridPhone& phone);
    friend ostream& operator<<(ostream& os, const HybridPhone& phone);
};

#endif