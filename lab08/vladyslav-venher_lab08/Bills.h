#pragma once
#include <string>
#include <iostream>
using namespace std;

struct GasBill {
    string name;
    int people;
    double amount;

    friend istream& operator>>(istream& in, GasBill& gb) {
        return in >> gb.name >> gb.people >> gb.amount;
    }

    friend ostream& operator<<(ostream& out, const GasBill& gb) {
        out << gb.name << " | People: " << gb.people << " | Amount: " << fixed << setprecision(2) << gb.amount;
        return out;
    }

    string toFileString() const {
        return name + " " + to_string(people) + " " + to_string(amount);
    }
};

struct WaterBill {
    string name;
    int lastMeter;
    double volume;
    double amount;

    friend istream& operator>>(istream& in, WaterBill& wb) {
        return in >> wb.name >> wb.lastMeter >> wb.volume >> wb.amount;
    }

    friend ostream& operator<<(ostream& out, const WaterBill& wb) {
        out << wb.name << " | Meter: " << wb.lastMeter << " | Volume: " << wb.volume
            << " | Amount: " << fixed << setprecision(2) << wb.amount;
        return out;
    }

    string toFileString() const {
        return name + " " + to_string(lastMeter) + " " + to_string(volume) + " " + to_string(amount);
    }
};

bool compareGas(const GasBill& a, const GasBill& b) {
    return a.amount < b.amount;
}

bool compareWater(const WaterBill& a, const WaterBill& b) {
    return a.volume > b.volume;
}
