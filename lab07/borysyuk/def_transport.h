#pragma once
#include <iostream>
#include <string>
using namespace std;

class DefaultTransport {
protected:
    double price;
    string destination;
public:
    DefaultTransport() : price(0.0), destination("none") {}
    DefaultTransport(double pr, const string& dest) : price(pr), destination(dest) {}

    virtual ~DefaultTransport() {}

    virtual string get_type() const = 0;
    virtual string get_object_type() const = 0;
    virtual void print(ostream& out) const {
        out << get_type() << " to " << destination << " for " << price;
    }
    virtual void input(istream& in) {
        in >> price >> destination;
    }

    double get_price() const { return price; }

    void set_dest(const string& dest) { destination = dest; }

    virtual void apply_discount() {
        if (price > 1000) price *= 0.9;
    }

    friend ostream& operator<<(ostream& out, const DefaultTransport& t) {
        t.print(out);
        return out;
    }

    friend istream& operator>>(istream& in, DefaultTransport& t) {
        t.input(in);
        return in;
    }
};