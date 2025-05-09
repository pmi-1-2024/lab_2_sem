#pragma once
#include "Struct.h"
#include <vector>
#include <string>

using namespace std;

void sortByName(vector<GasBill>&);
void sortByName(vector<WaterBill>&);

vector<string> filterByAmount(const vector<GasBill>&, double);
vector<string> filterByAmount(const vector<WaterBill>&, double);
