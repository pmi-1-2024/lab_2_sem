#pragma once
#include "ElectroDevice.h"
using namespace std;
class VacuumCleaner :public ElectroDevice {
private:
    int power;
    string color;

public:
    

    
    VacuumCleaner(string n = "", string b = "", double p = 0.0, int pow = 0, string col = "");
    ~VacuumCleaner();

    void print(ostream& os) const override;
    void read(istream& is) override;
};
