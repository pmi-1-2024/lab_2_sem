#pragma once
#include "ElectroDevice.h"

class FoodProcessor :virtual  public ElectroDevice {
protected:
    int power;
    int numFunctions;

public:
    FoodProcessor(string n = "", string b = "", double p = 0.0, int pow = 0, int nf = 0);
    ~FoodProcessor();
    FoodProcessor(const FoodProcessor& other);

    
    FoodProcessor& operator=(const FoodProcessor& other);
    
    void print(ostream& os) const override;
    void read(istream& is) override;
    friend ostream& operator<<(ostream& os, const FoodProcessor& device);
    friend istream& operator>>(istream& is, FoodProcessor& device);
   
};