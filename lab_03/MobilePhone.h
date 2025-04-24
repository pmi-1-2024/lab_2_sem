#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H
#include "Phone.h"

class MobilePhone : virtual public Phone {
protected:
    string color;
    int memory;
public:
    MobilePhone(string name = "", string brand = "", double price = 0.0, string color = "", int memory = 0);
    void print(ostream& os) const override;
    void read(istream& is) override;
};

#endif