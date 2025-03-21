#ifndef HYBRIDPHONE_H
#define HYBRIDPHONE_H
#include "MobilePhone.h"
#include "RadioPhone.h"

class HybridPhone : public MobilePhone, public RadioPhone {
public:
    HybridPhone(string name = "", string brand = "", double price = 0.0, string color = "", int memory = 0, int range = 0, bool answeringMachine = false);
    void print(ostream& os) const override;
    void read(istream& is) override;
};
#endif