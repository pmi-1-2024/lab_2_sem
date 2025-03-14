#pragma once
#include "ElectroDevice.h"

using namespace std;
class WashingMachine : public ElectroDevice {
private:
    int numPrograms;
    double volume;

public:
    WashingMachine(string n = "", string b = "", double p = 0.0, int np = 0, double vol = 0.0);
    ~WashingMachine();
    

    
    void print(ostream& os) const override;
    void read(istream& is) override;
};