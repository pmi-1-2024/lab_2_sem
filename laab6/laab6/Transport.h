#include <iostream>
#include <string>
#pragma once
using namespace std;

template <typename T>
class Transport {
protected:
    T typeOfCargo;
    double costOfDeliv;
    string destin;
    double maxLoad;

public:
    Transport(T tpCrg = T(), double cstDel = 0, string dstn = "", double maxL = 0)
        : typeOfCargo(tpCrg), costOfDeliv(cstDel), destin(dstn), maxLoad(maxL) {}

    virtual void updateDestination(string newDest) {
        destin = newDest;
    }

    virtual void printInfo() const {
        cout << "Cargo: " << typeOfCargo << ", Cost: $" << costOfDeliv << ", Destination: " << destin << ", Max Load: " << maxLoad << "kg" << endl;
    }


    void updateCargoInfo(T newCargoType, double newCost) {
        typeOfCargo = newCargoType;
        costOfDeliv = newCost;
    }

    double discount() const {
        return costOfDeliv * 0.85; 
    }

    double getMaxLoad() const { return maxLoad; }


    friend ostream& operator<<(ostream& os, const Transport& t) {
        os << t.typeOfCargo << " " << t.costOfDeliv << " " << t.destin << " " << t.maxLoad;
        return os;
    }
    
    friend istream& operator>>(istream& is, Transport& t) {
        is >> t.typeOfCargo >> t.costOfDeliv >> t.destin >> t.maxLoad;
        return is;
    }
};

