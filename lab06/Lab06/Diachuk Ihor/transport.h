#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
using namespace std;

template <typename T>
class Transport {
protected:
    T cargo;
    string destination;
    double cost;

public:
    Transport();
    Transport(T c, string d, double cost);
    virtual ~Transport();

    virtual void updateCargo(T newCargo);
    virtual void updateDestination(const string& newDest);
    virtual double calculateDiscountedCost() const;
    virtual void print() const;

    T getCargo() const;
    string getDestination() const;
    double getCost() const;
};

#include "transport.cpp" 

#endif