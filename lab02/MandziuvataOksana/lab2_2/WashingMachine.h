#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include "Electroprilad.h"

class WashingMachine : public Electroprilad {
private:
    int programs;  
    double volume;  

public:
    WashingMachine();
    WashingMachine(string n, string f, int p, int prog, double vol);
    WashingMachine(const WashingMachine& wm);
    ~WashingMachine() {}

    void print(ostream& os) const override;
    void write(istream& is) override;
};

#endif
