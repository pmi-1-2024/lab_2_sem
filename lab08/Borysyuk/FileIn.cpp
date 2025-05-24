#include "FileIn.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

void readBills(const string& filename,
    vector<GasBill>& gasBills,
    vector<WaterBill>& waterBills)
{
    ifstream file(filename);
    if (!file.is_open())
        throw runtime_error("Cannot open file: " + filename);

    string type;
    while (file >> type) {
        if (type == "gas") {
            GasBill g;
            file >> g.name >> g.persons >> g.amount;
            if (file.fail())
                throw runtime_error("Invalid gas bill format.");
            gasBills.push_back(g);
        }
        else if (type == "water") {
            WaterBill w;
            file >> w.name >> w.meterReading >> w.volume >> w.amount;
            if (file.fail())
                throw runtime_error("Invalid water bill format.");
            waterBills.push_back(w);
        }
        else {
            throw runtime_error("Unknown record type: " + type);
        }
    }
}

void writeGasBills(const vector<GasBill>& bills, const string& filename) {
    ofstream out(filename);
    for (const auto& b : bills)
        out << b.name << " " << b.persons << " " << b.amount << '\n';
}

void writeWaterBills(const vector<WaterBill>& bills, const string& filename) {
    ofstream out(filename);
    for (const auto& b : bills)
        out << b.name << " " << b.meterReading << " "
        << b.volume << " " << b.amount << '\n';
}

void printNames(const vector<string>& names, const string& filename) {
    ofstream out(filename);
    for (const auto& name : names)
        out << name << '\n';
}



