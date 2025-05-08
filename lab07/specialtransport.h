#ifndef SPECIALTRANSPORT_H
#define SPECIALTRANSPORT_H

#include <iostream>
#include <string>
#include "transport.h"
using namespace std;

template <typename T>
class SpecialTransport : public Transport<T> {
private:
    string specialConditions;
public:
    SpecialTransport() : Transport<T>(T(), "", 0.0, 0.0), specialConditions(" ") {}
    SpecialTransport(T cargo, string destination, double cost, double weight, string cond)
        : Transport<T>(cargo, destination, cost, weight), specialConditions(cond) {}

    double countDiscount(double) override {
        return Transport<T>::cost * 0.95;
    }


    void displayInformation(ostream& os) override {
        Transport<T>::displayInformation(os);
        os << "Special Conditions: " << specialConditions << endl;
    }
    void setSpecialConditions(const string& cond) { specialConditions = cond; }
    friend istream& operator>> (istream& is, SpecialTransport<T>& t) {
        is >> t.cargo >> t.destination >> t.cost >> t.weight >> t.specialConditions;
        return is;
    }

    friend ostream& operator<<(ostream& os, const SpecialTransport<T>& t) {
        os << "Cargo: " << t.cargo << "\nDestination: " << t.destination << "\nCost: " << t.cost << "\nWeight:" << t.weight << "\nSpecial conditions: " << t.specialConditions;
        return os;
    }
};

#endif