#pragma once
#include <iostream>
#include <string>
#include "Cargo.h"
using namespace std;

template <typename T = Cargo*>  
class Transport {
private:
    T load;  
    string destination;
    double price;
    double maxCapacity;
    double currentLoad;
public:
    Transport() : load(nullptr), destination(""), price(0.0), maxCapacity(0.0), currentLoad(0.0) {}
    Transport(T l, string dest, double p, double cap) : load(l), destination(dest), price(p), maxCapacity(cap), currentLoad(0.0) {}
    ~Transport() { delete load; }  

    T getLoad() const { return load; }
    string getDestination() const { return destination; }
    double getPrice() const { return price; }
    double getMaxCapacity() const { return maxCapacity; }
    double getCurrentLoad() const { return currentLoad; }

    void setLoad(T l) {
        delete load;  
        load = l;
    }
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
        char cargoType;
        is >> cargoType;
        if (cargoType == 'P') {
            string name;
            is >> name;
            load = new Person(name);
        }
        else {
            string type;
            double weight;
            is >> type >> weight;
            load = new Goods(type, weight);
        }
        is >> destination >> price >> maxCapacity;
    }
    friend istream& operator>>(istream& is, Transport& t) {
        t.read(is);
        return is;
    }

    virtual void print(ostream& os) {
        os << "Load: " << *load << ", Destination: " << destination
            << ", Price: " << price << ", Max capacity: " << maxCapacity
            << ", Current load: " << currentLoad;
    }
    friend ostream& operator<<(ostream& os, Transport& t) {
        t.print(os);
        return os;
    }

    virtual void saveToFile(ostream& os) const {
        os << getTypeChar() << " ";
        if (dynamic_cast<Person*>(load)) {
            os << "P " << dynamic_cast<Person*>(load)->getName();
        }
        else {
            os << "G " << dynamic_cast<Goods*>(load)->getType() << " " << dynamic_cast<Goods*>(load)->getWeight();
        }
        os << " " << destination << " " << price << " " << maxCapacity;
    }
};

