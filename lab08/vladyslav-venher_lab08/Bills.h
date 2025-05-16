#pragma once
#include <string>
using namespace std;

struct GasBill {
    string name;
    int people;
    double amount;
};

struct WaterBill {
    string name;
    int lastMeter;
    double volume;
    double amount;
};

bool compareGas(const GasBill& a, const GasBill& b) {
    return a.amount < b.amount;
}

bool compareWater(const WaterBill& a, const WaterBill& b) {
    return a.volume > b.volume;
}
