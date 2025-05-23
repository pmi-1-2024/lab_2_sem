#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include "Phone.h"

  class MobilePhone : virtual public Phone {

private:

    string color;
    int memory;


public:

    MobilePhone();
    void read(istream& in) override;
    void write(ostream& out) const override;
};

#endif
