#ifndef RADIOPHONE_H
#define RADIOPHONE_H
#include "Phone.h"

class RadioPhone : public Phone {
private:
    int range;
    bool answeringMachine;
public:
    RadioPhone(string name = "", string brand = "", double price = 0.0, int range = 0, bool answeringMachine = false);
    void print(ostream& os) const override;
    void read(istream& is) override;
    bool hasAnsweringMachine() const { return answeringMachine; }
};

#endif