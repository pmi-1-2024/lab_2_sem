#pragma once
#include <iostream>
#include <string>
#include <type_traits>
#include <fstream>
#include <limits>
#include <stdexcept>
#include "Person.h"
#include "Cargo.h"
#include "TransportException.h"

using namespace std;

template <typename T>
class Transport {
protected:
    T cargo; 
    string destination;
    double cost;

public:
    Transport() : cargo(), destination(""), cost(0.0) {}
    Transport(T c, string d, double co) : cargo(c) { 
        if (d.empty()) {
            throw invalid_argument("Destination cannot be empty at construction.");
        }
        destination = d;

        if (co < 0) {
            throw invalid_argument("Cost cannot be negative at construction.");
        }
        cost = co;
    }
    virtual ~Transport() {}

    T getCargo() const { return cargo; }
    string getDestination() const { return destination; }
    double getCost() const { return cost; }

    void setCargo(const T& c) { cargo = c; } 
    void setDestination(const string& d) { destination = d; }
    void setCost(double c) { cost = c; }


    virtual double calculateDiscount() const {
        if constexpr (is_same<T, Person>::value) {
            const Person* p = static_cast<const Person*>(static_cast<const void*>(&cargo));
            if (p->getAge() < 15) 
                return cost * 0.3;
        }
        else if constexpr (is_same<T, Cargo>::value) {
            const Cargo* c = static_cast<const Cargo*>(static_cast<const void*>(&cargo));
            string cond = c->getSpecialCondition(); 
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
        if (out.fail()) throw ios_base::failure("Error saving cargo/person to stream.");

        out << destination << "\n";
        if (out.fail()) throw ios_base::failure("Error saving destination to stream.");

        out << cost << "\n";
        if (out.fail()) throw ios_base::failure("Error saving cost to stream.");
    }


    virtual void load(istream& in) {
        try {
            cargo.load(in); 
        }
        catch (const exception& e) {
            throw TransportException("Failed to load cargo/person: " + string(e.what()));
        }

        if (in.peek() == '\n') in.ignore();

        string tempDest;
        getline(in, tempDest);
        if (in.fail()) {
            throw ios_base::failure("Error reading destination from stream.");
        }
        if (tempDest.empty()) {
            throw TransportException("Loaded destination is empty.");
        }

        double tempCost;
        in >> tempCost;
        if (in.fail()) {
            in.clear();
            in.ignore();
            throw ios_base::failure("Invalid format for cost.");
        }
        if (tempCost < 0) {
            in.ignore();
            throw TransportException("Negative cost is not allowed: " + to_string(tempCost));
        }
        destination = tempDest;
        cost = tempCost;

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