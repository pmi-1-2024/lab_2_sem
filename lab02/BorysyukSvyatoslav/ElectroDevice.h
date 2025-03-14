#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class ElectroDevice {
protected:
    string name;
    string brand;
    double price;

public:
    ElectroDevice(string n = "", string b = "", double p = 0.0);
    virtual ~ElectroDevice(); 

    virtual void print(ostream& os) const;
    virtual void read(istream& is);

     string getName() const;
     string getBrand() const; 
     double getPrice() const; 

    friend ostream& operator<<(ostream& os, const ElectroDevice& device);
    friend istream& operator>>(istream& is, ElectroDevice& device);
};
