#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
class Transport {
protected:
    T cargo;
    string destination;
    double cost;

public:
    Transport() : cargo(T()), destination(""), cost(0.0) {}

    Transport(T cargo, string destination, double cost)
        : cargo(cargo), destination(destination), cost(cost) {
    }

    void updateCargo(T newCargo) { cargo = newCargo; }
    void updateDestination(string newDestination) { destination = newDestination; }
    void updatecCost(double newCost) { cost = newCost; }

    virtual double countDiscount(double percent) {
        return cost - (cost * percent / 100.0);
    }

    virtual void displayInformation(ofstream& os) {
        os << "Cargo: " << cargo << "\nDestination: " << destination << "\nCost: " << cost << endl;
    }

    double getCost() const { return cost; }

    friend istream& operator>>(istream& is, Transport<T>& t) {
        is >> t.cargo >> t.destination >> t.cost;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Transport<T>& t) {
        os << "Cargo:" << t.cargo << "\nDestination:" << t.destination << "\nCost:" << t.cost;
        return os;
    }
};

#endif
