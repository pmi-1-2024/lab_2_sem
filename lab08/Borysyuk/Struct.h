#pragma once
#include <string>

using namespace std;

struct GasBill {
    string name;
    int persons;
    double amount;
};

struct WaterBill {
    string name;
    int meterReading;
    double volume;
    double amount;
};