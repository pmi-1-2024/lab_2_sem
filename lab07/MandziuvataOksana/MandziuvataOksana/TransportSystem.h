#ifndef TRANSPORTSYSTEM_H
#define TRANSPORTSYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "Cargo.h"
#include "Person.h"
#include "TransportException.h"

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
        if (in.fail()) throw runtime_error("Error reading transport data.");
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
        if (in.fail()) throw runtime_error("Error reading category for special transport.");
    }

    void print(ostream& out) const override {
        Transport<T>::print(out);
        out << "Category: " << category << endl;
    }
};

void loadTransports(ifstream& input, Transport<Cargo>** arr, int& size) {
    if (!input) throw runtime_error("Input file cannot be opened!");

    int type;
    size = 0;
    while (input >> type) {
        if (size >= 8) break;

        if (type == 1) {
            arr[size] = new Transport<Cargo>();
        }
        else if (type == 2) {
            arr[size] = new SpecialTransport<Cargo>();
        }
        else {
            throw TransportException("Unknown transport type in file.");
        }

        try {
            input >> *arr[size];
        }
        catch (...) {
            delete arr[size];
            throw;
        }

        ++size;
    }
}

int findMostExpensive(Transport<Cargo>** arr, int size) {
    if (size == 0) throw TransportException("No transports available.");

    int maxIdx = 0;
    double maxCost = arr[0]->getCost();
    for (int i = 1; i < size; ++i) {
        if (arr[i]->getCost() > maxCost) {
            maxCost = arr[i]->getCost();
            maxIdx = i;
        }
    }
    return maxIdx;
}

void applyDiscounts(Transport<Cargo>** arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i]->setCost(arr[i]->calculateFinalCost());
    }
}

double totalCost(Transport<Cargo>** arr, int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        total += arr[i]->getCost();
    }
    return total;
}

void showMenu() {
    cout << "\n--- Transport System Menu ---\n";
    cout << "1. Display all transports\n";
    cout << "2. Find most expensive transport\n";
    cout << "3. Apply discounts\n";
    cout << "4. Filter by cargo type\n";
    cout << "5. Change cargo and destination\n";
    cout << "6. Show total cost\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

void handleChoice(int choice, Transport<Cargo>** arr, int size) {
    switch (choice) {
    case 1:
        for (int i = 0; i < size; ++i) {
            cout << "\n[" << i << "]\n" << *arr[i];
        }
        break;
    case 2:
        cout << "Most expensive transport:\n";
        cout << *arr[findMostExpensive(arr, size)];
        break;
    case 3:
        applyDiscounts(arr, size);
        cout << "Discounts applied.\n";
        break;
    case 4: {
        string type;
        cout << "Enter cargo type to filter (e.g. Passenger, Medical): ";
        cin >> type;
        for (int i = 0; i < size; ++i) {
            if (arr[i]->getCargo().getType() == type) {
                cout << *arr[i];
            }
        }
        break;
    }
    case 5: {
        int index;
        cout << "Enter index of transport to modify: ";
        cin >> index;
        if (cin.fail() || index < 0 || index >= size) throw TransportException("Invalid transport index!");

        Cargo newCargo;
        string newDest;
        cout << "New cargo: ";
        cin >> newCargo;
        cout << "New destination: ";
        cin >> newDest;
        arr[index]->setCargo(newCargo);
        arr[index]->setDestination(newDest);
        cout << "Updated transport:\n" << *arr[index];
        break;
    }
    case 6:
        cout << "Total cost: " << totalCost(arr, size) << endl;
        break;
    case 0:
        cout << "Goodbye!\n";
        break;
    default:
        throw invalid_argument("Invalid menu choice.");
    }
}

#endif
