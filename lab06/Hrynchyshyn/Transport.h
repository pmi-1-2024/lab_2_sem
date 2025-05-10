#pragma once
#include <iostream>
#include <string>
#include <type_traits>
#include <fstream>
#include "Person.h"
#include "Cargo.h"

using namespace std;

template <typename T>
class Transport {
protected:
    T cargo;
    string destination;
    double cost;

public:
    Transport() : cargo(), destination(""), cost(0.0) {}
    Transport(T c, string d, double co) : cargo(c), destination(d), cost(co) {}
    virtual ~Transport() {}

    T getCargo() const { return cargo; }
    string getDestination() const { return destination; }
    double getCost() const { return cost; }

    void setCargo(const T& c) { cargo = c; }
    void setDestination(const string& d) { destination = d; }
    void setCost(double c) { cost = c; }

    virtual double calculateDiscount() const {
        if constexpr (is_same<T, Person>::value) {
            if (cargo.getAge() < 15)
                return cost * 0.3;
        }
        else if constexpr (is_same<T, Cargo>::value) {
            string cond = cargo.getSpecialCondition();
            if (cond == "medicine" || cond == "volunteer") return cost * 0.4;
        }
        return 0.0;
    }

    virtual void displayInfo() const {
        cout << "Standard Transport:\n";
        cout << "Cargo/Person Info:\n" << cargo;
        cout << "Destination: " << destination << "\nCost: " << cost << "\n";
    }

    virtual void save(ostream& out) const {
        cargo.save(out);
        out << destination << "\n";
        out << cost << "\n";
    }

    virtual void load(istream& in) {
        cargo.load(in);
        in.ignore();
        getline(in, destination);
        in >> cost;
        in.ignore();
    }

    friend istream& operator>>(istream& in, Transport<T>& t) {
        t.load(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Transport<T>& t) {
        t.save(out);
        return out;
    }
};