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
    double weight;

public:
    Transport() : cargo(T()), destination(""), cost(0.0) {}
    Transport(T c, string destination, double cost, double weight)
        : cargo(c), destination(destination), cost(cost), weight(weight) {
    }

    virtual double countDiscount(double percent) { return cost - (cost * percent / 100.0); }

    virtual void displayInformation(ostream& os) {
        os << "Cargo: " << cargo
            << "\nDestination: " << destination
            << "\nCost: " << cost
            << "\nWeight: " << weight << " kg" << endl;
    }
    void setCargo(T c) { cargo = c; }
    void setDestination(const string& d) { destination = d; }
    void setCost(double c) { cost = c; }
    void setWeight(double w) { weight = w; }
    double getCost() const { return cost; }
    double getWeight() const { return weight; }

    friend istream& operator>>(istream& is, Transport<T>& t) {
        is >> t.cargo >> t.destination >> t.cost >> t.weight;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Transport<T>& t) {
        os << "Cargo: " << t.cargo << "\nDestination: " << t.destination << "\nCost: " << t.cost << "\nWeight:" << t.getWeight() << "kg";
        return os;
    }
};

#endif