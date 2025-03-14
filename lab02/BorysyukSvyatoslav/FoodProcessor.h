#pragma once
#include "ElectroDevice.h"

class FoodProcessor : public ElectroDevice {
private:
    int power;
    int numFunctions;

public:
    FoodProcessor(string n = "", string b = "", double p = 0.0, int pow = 0, int nf = 0);
    ~FoodProcessor();
    
    void print(ostream& os) const override;
    void read(istream& is) override;
   
};