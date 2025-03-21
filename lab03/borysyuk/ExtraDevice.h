#pragma once
#include"VacuumCleaner.h"
#include"WashingMachine.h"
class ExtraDevice : public VacuumCleaner, public WashingMachine {
public:

    ExtraDevice(string n = "", string b = "", double p = 0.0, int pow = 0, string col = "",int np = 0 ,double vol = 0.0);
    ~ExtraDevice();

    void print(ostream& os) const override;
    void read(istream& is) override;

    ExtraDevice(const ExtraDevice& other);

    
    ExtraDevice& operator=(const ExtraDevice& other);


    friend ostream& operator<<(ostream& os, const ExtraDevice& device);
    friend istream& operator>>(istream& is, ExtraDevice& device);

};