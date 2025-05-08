#ifndef TRANSPORTSYSTEM_H
#define TRANSPORTSYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include "Cargo.h"
#include "Person.h"

using namespace std;

template<typename T>
class Transport {
protected:
    T cargo;
    string destination;
    double baseCost;

public:
    Transport() : cargo(T()), destination("Unknown"), baseCost(0.0) {}
    Transport(T c, string dest, double cost) : cargo(c), destination(dest), baseCost(cost) {}

    T getCargo() const { return cargo; }
    string getDestination() const { return destination; }
    double getCost() const { return baseCost; }

    void setCargo(const T& c) { cargo = c; }
    void setDestination(const string& dest) { destination = dest; }
    void setCost(double cost) { baseCost = cost; }

    virtual double getDiscount() const {
        if (cargo.getType() == "Medical") return baseCost * 0.3;
        if (cargo.getType() == "Passenger") return baseCost * 0.2;
        return 0.0;
    }

    virtual double calculateFinalCost() const {
        return baseCost - getDiscount();
    }

    virtual void read(istream& in) {
        in >> cargo >> destination >> baseCost;
    }

    virtual void print(ostream& out) const {
        out << "Cargo: " << cargo << "\nDestination: " << destination << "\nCost: " << baseCost << endl;
    }

    friend istream& operator>>(istream& in, Transport& t) {
        t.read(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Transport& t) {
        t.print(out);
        return out;
    }
};

template<typename T>
class SpecialTransport : public Transport<T> {
private:
    string category;

public:
    SpecialTransport() : Transport<T>(), category("Standard") {}
    SpecialTransport(T c, string dest, double cost, string cat)
        : Transport<T>(c, dest, cost), category(cat) {}

    double getDiscount() const override {
        if (category == "VIP") return this->baseCost * 0.4;
        if (category == "Premium") return this->baseCost * 0.5;
        return 0.0;
    }

    double calculateFinalCost() const override {
        return this->baseCost - Transport<T>::getDiscount() - getDiscount();
    }

    void read(istream& in) override {
        Transport<T>::read(in);
        in >> category;
    }

    void print(ostream& out) const override {
        Transport<T>::print(out);
        out << "Category: " << category << endl;
    }
};

void loadTransports(ifstream& input, Transport<Cargo>** arr, int& size);
int findMostExpensive(Transport<Cargo>** arr, int size);
double totalCost(Transport<Cargo>** arr, int size);
void applyDiscounts(Transport<Cargo>** arr, int size);
void showMenu();
void handleChoice(int choice, Transport<Cargo>** arr, int size);

#endif
