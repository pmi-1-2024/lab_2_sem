#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Transport {
protected:
    T cargo;
    string destination;
    double cost;
    string cargoType;

public:
    Transport() : cargo(T()), destination(""), cost(0.0), cargoType("") {}
    Transport(T cargo, string destination, double cost, string cargoType)
        : cargo(cargo), destination(destination), cost(cost), cargoType(cargoType) {
    }

    virtual ~Transport() {}

    T getCargo() const { return cargo; }
    string getDestination() const { return destination; }
    double getCost() const { return cost; }
    string getCargoType() const { return cargoType; }

    void updateCargo(const T& newCargo) { cargo = newCargo; }
    void updateDestination(const string& newDestination) { destination = newDestination; }

    virtual double calculateDiscount() const { return 0.0; }

    virtual void read(istream& is) {
        try {
            is >> cargo >> destination >> cost >> cargoType;
            if (is.fail()) throw invalid_argument("Failed to read transport data!");
        }
        catch (const exception& e) {
            cerr << "Error reading transport data: " << e.what() << endl;
        }
    }

    virtual void print(ostream& os) const {
        os << "Cargo: " << cargo << ", Destination: " << destination
            << ", Cost: " << cost << ", Type: " << cargoType;
    }

    friend istream& operator>>(istream& is, Transport<T>& t) {
        t.read(is);
        return is;
    }

    friend ostream& operator<<(ostream& os, const Transport<T>& t) {
        t.print(os);
        return os;
    }
};
