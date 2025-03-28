#pragma once
#include "ElectroDevice.h"
using namespace std;
class VacuumCleaner :virtual public ElectroDevice {
protected:
    int power;
    string color;

public:
 
    VacuumCleaner(string n = "", string b = "", double p = 0.0, int pow = 0, string col = "");
    ~VacuumCleaner();

    void print(ostream& os) const override;
    void read(istream& is) override;

   
    VacuumCleaner(const VacuumCleaner& other);
    VacuumCleaner& operator=(const VacuumCleaner& other);


    friend ostream& operator<<(ostream& os, const VacuumCleaner& device);
    friend istream& operator>>(istream& is, VacuumCleaner& device);
};
