#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Delivery {
protected:
    T load;
    string destination;
    double price;

public:
    Delivery() : load(), destination(""), price(0.0) {}
    Delivery(T l, string d, double p) : load(l), destination(d), price(p) {}

    virtual char getTypeChar() const { return 't'; }
    virtual double discount(int dis) { return price - price * dis / 100.0; }
    virtual int getDiscount() const { return 0; }

    string getLoad() const { return load; }
    string getDestination() const { return destination; }
    double getPrice() const { return price; }

    void setLoad(const T& l) { load = l; }
    void setDestination(const string& d) { destination = d; }
    void setPrice(double p) { price = p; }

    virtual void read(istream& in) {
        in >> load >> destination >> price;
        if (!in) throw runtime_error("Failed to read delivery.");
    }

    virtual void print(ostream& out) const {
        out << "Load: " << load << ", Destination: " << destination << ", Price: " << price;
    }

    friend istream& operator>>(istream& in, Delivery<T>& d) {
        d.read(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Delivery<T>& d) {
        d.print(out);
        return out;
    }
};
