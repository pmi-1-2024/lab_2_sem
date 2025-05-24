#pragma once
#include "Struct.h"
#include <vector>
#include <string>

using namespace std;

void readBills(const string& filename,
    vector<GasBill>& gasBills,
    vector<WaterBill>& waterBills);

void writeGasBills(const vector<GasBill>& bills, const string& filename);
void writeWaterBills(const vector<WaterBill>& bills, const string& filename);
void printNames(const vector<string>& names, const string& filename);
