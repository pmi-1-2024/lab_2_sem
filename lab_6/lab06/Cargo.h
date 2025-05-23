#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cargo {
private:
    string name;
    double weight;
public:
    Cargo();
    Cargo(const string& name, double weight);

    void setName(const string& name);
    void setWeight(double weight);

    string getName() const;
    double getWeight() const;

    friend ostream& operator<<(ostream& os, const Cargo& cargo);
    friend istream& operator>>(istream& is, Cargo& cargo);
};