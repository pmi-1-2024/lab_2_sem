#pragma once

#include <string>
using namespace std;

class CargoTypes {
public:
    static const string PASSENGERS;
    static const string FREIGHT;
    static const string URGENT;
    static const string FRAGILE;
};

const string CargoTypes::PASSENGERS = "passengers";
const string CargoTypes::FREIGHT = "freight";
const string CargoTypes::URGENT = "urgent";
const string CargoTypes::FRAGILE = "fragile";

