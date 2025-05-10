#pragma once
#include "Transport.h"
#include "Cargo.h"

class SpecialTransport : public Transport<Cargo> {
public:
    SpecialTransport() : Transport() {}
    SpecialTransport(Cargo c, string d, double co) : Transport(c, d, co) {}

    double calculateDiscount() const override {
        string sc = this->cargo.getSpecialCondition();
        if (sc == "medicine") return cost * 0.4;
        if (sc == "urgent") return cost * 0.1;
        if (sc == "fragile") return cost * 0.05;
        return 0.0;
    }

    void displayInfo() const override {
        cout << "Special Cargo Transport:\n";
        cout << "Cargo: " << cargo.getName() << " [" << cargo.getSpecialCondition() << "]\n";
        cout << "Destination: " << destination << "\nCost: " << cost << "\n";
    }

    void save(ostream& out) const override {
        Transport<Cargo>::save(out);
    }

    void load(istream& in) override {
        Transport<Cargo>::load(in);
    }

    friend istream& operator>>(istream& in, SpecialTransport& t) {
        t.load(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, const SpecialTransport& t) {
        t.save(out);
        return out;
    }
};