#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Transport {
private:
    T load;
    string destination;
    double price;
    double maxCapacity;
    double currentLoad;
public:
    Transport() : load(T()), destination(""), price(0.0), maxCapacity(0.0), currentLoad(0.0) {}
    Transport(T l, string dest, double p, double cap) : load(l), destination(dest), price(p), maxCapacity(cap), currentLoad(0.0) {}

    T getLoad() const { return load; }
    string getDestination() const { return destination; }
    double getPrice() const { return price; }
    double getMaxCapacity() const { return maxCapacity; }
    double getCurrentLoad() const { return currentLoad; }

    void setLoad(T l) { load = l; }
    void setDestination(string d) { destination = d; }
    void setPrice(double p) { price = p; }
    void setMaxCapacity(double cap) { maxCapacity = cap; }
    void setCurrentLoad(double load) { currentLoad = load; }

    double getFreeCapacity() const {
        return maxCapacity - currentLoad;
    }

    virtual double discount(int percent) {
        return price - price * percent / 100.0;
    }

    virtual char getTypeChar() const {
        return 't';
    }

    virtual void read(istream& is) {
        is >> load >> destination >> price >> maxCapacity;
    }
    friend istream& operator>>(istream& is, Transport& t) {
        t.read(is);
        return is;
    }

    virtual void print(ostream& os) {
        os << "Load type: " << load << ", Destination: " << destination << ", Price: " << price << ", Max capacity: " << maxCapacity << ", Current load: " << currentLoad;
    }
    friend ostream& operator<<(ostream& os, Transport& t) {
        t.print(os);
        return os;
    }

    virtual void saveToFile(ostream& os) const {
        os << getTypeChar() << " " << load << " " << destination << " " << price << " " << maxCapacity;
    }

    virtual ~Transport() {}
};

