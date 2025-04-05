#ifndef HYBRIDPHONE_H
#define HYBRIDPHONE_H

#include "MobilePhone.h"
#include "RadioPhone.h"

class HybridPhone : public MobilePhone, public RadioPhone {

public:

    HybridPhone();

    void read(istream& in) override;
    void write(ostream& out) const override;
};

#endif
