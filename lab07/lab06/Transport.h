#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Transport {
protected:
    T cargo;
    string dest;
    double price;

public:
    Transport() : cargo(), dest(""), price(0) {}
    Transport(T c, string d, double p) : cargo(c), dest(d), price(p) {}

    T getCargo() const { return cargo; }
    string getDest() const { return dest; }
    double getPrice() const { return price; }

    void setCargo(T c) { cargo = c; }
    void setDest(string d) { dest = d; }
    void setPrice(double p) { price = p; }

    virtual void discount() {
        if (cargo == "Medical" || cargo == "Special") {
            price *= 0.9;
        }
    }

    friend ostream& operator<<(ostream& os, const Transport<T>& t) {
        os << "Cargo: " << t.cargo << ", Destination: " << t.dest << ", Price: " << t.price;
        return os;
    }

    friend istream& operator>>(istream& is, Transport<T>& t) {
        is >> t.cargo >> t.dest >> t.price;
        return is;
    }

    virtual ~Transport() {}
};

#endif