#pragma once
#include "ElectroDevice.h"

using namespace std;
class WashingMachine :virtual public ElectroDevice {
protected:
    int numPrograms;
    double volume;

public:
    WashingMachine(string n = "", string b = "", double p = 0.0, int np = 0, double vol = 0.0);
    ~WashingMachine();

    WashingMachine(const WashingMachine& other);
    WashingMachine& operator=(const WashingMachine& other);

   
    
    void print(ostream& os) const override;
    void read(istream& is) override;
    friend ostream& operator<<(ostream& os, const WashingMachine& device);
    friend istream& operator>>(istream& is, WashingMachine& device);
};