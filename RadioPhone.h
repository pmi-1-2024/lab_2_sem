#ifndef RADIOPHONE_H
#define RADIOPHONE_H

#include "Phone.h"

class RadioPhone : virtual public Phone {

private:

    double range;
    bool answeringMachine;

public:

    RadioPhone();
    void read(istream& in) override;
    void write(ostream& out) const override;

    bool hasAnsweringMachine() const override;
};

#endif
