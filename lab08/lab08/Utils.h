#pragma once
#include <string>
#include <deque>
#include <map>
using namespace std;

using Material = deque<string>;
using MaterialEntry = Material;
using BrigadeMap = map<int, pair<string, deque<MaterialEntry>>>;

void readData(const string& filename, BrigadeMap& brigades, map<int, double>& costs);
void writeSortedBrigades(const BrigadeMap& brigades, const map<int, double>& costs, const string& filename);
void writeMinCostBrigades(const map<int, double>& costs, const BrigadeMap& brigades, const string& filename);