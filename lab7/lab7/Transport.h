#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
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
        : typeOfCargo(tpCrg), costOfDeliv(cstDel), destin(dstn), maxLoad(maxL) {
        if (cstDel < 0 || maxL < 0) throw invalid_argument("Cost or max load cannot be negative");
    }

    virtual void updateDestination(string newDest) {
        destin = newDest;
    }

    virtual void printInfo() const {
        cout << "Passenger: " << typeOfCargo << ", Cost: $" << costOfDeliv << ", Destination: "
            << destin << ", Max Load: " << maxLoad << "kg" << endl;
    }

    void updatePassengerInfo(const string& newName, int newAge) {
        if (newAge < 0) throw invalid_argument("Passenger age cannot be negative");
        typeOfCargo.name = newName;
        typeOfCargo.age = newAge;
    }

    void updateCost(double newCost) {
        if (newCost < 0) throw invalid_argument("New delivery cost cannot be negative");
        costOfDeliv = newCost;
    }

    T& getCargoType() { return typeOfCargo; }

    double getMaxLoad() const { return maxLoad; }

    friend ostream& operator<<(ostream& os, const Transport& t) {
        os << t.typeOfCargo << " " << t.costOfDeliv << " " << t.destin << " " << t.maxLoad;
        return os;
    }

    friend istream& operator>>(istream& is, Transport& t) {
        is >> t.typeOfCargo >> t.costOfDeliv >> t.destin >> t.maxLoad;
        if (t.costOfDeliv < 0 || t.maxLoad < 0) throw invalid_argument("Invalid transport data during input");
        return is;
    }
};
