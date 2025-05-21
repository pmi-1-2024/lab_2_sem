#pragma once
#include <string>
#include <vector>
using namespace std;

struct Material {
    string date;
    string name;
    double volume;
    double cost;
};

struct TeamData {
    int teamNumber;
    string foreman;
    vector<Material> materials;
};

struct MaterialSummary {
    double totalVolume = 0;
    double totalCost = 0;
};
