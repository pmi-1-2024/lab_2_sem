#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Transport {
protected:
    T cargo;
    char destination[100];
    double cost;
public:
    Transport(T cargo, const char* destination, double cost);
    virtual ~Transport() {}

    void setCargo(T cargo);
    void setDestination(const char* destination);
    void setCost(double cost);

    T getCargo() const;
    const char* getDestination() const;
    double getCost() const;

    virtual double calculateDiscount(double percent) const;
    virtual void print() const;
};