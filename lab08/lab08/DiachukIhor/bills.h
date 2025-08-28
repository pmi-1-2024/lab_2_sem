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
    int volumePaid;
    double amount;
};

inline bool compareGasByName(const GasBill& a, const GasBill& b) {
    return a.name < b.name;
}

inline bool compareWaterByAmountDesc(const WaterBill& a, const WaterBill& b) {
    return a.amount > b.amount;
}