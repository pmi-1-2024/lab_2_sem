#include "Utils.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iostream>

void readData(const string& filename, BrigadeMap& brigades, map<int, double>& costs) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        throw runtime_error("Couldn't open input file.");
    }

    string line;
    while (getline(fin, line)) {
        // remove UTF-8 BOM if present
        if (line.size() >= 3 && line[0] == '\xEF' && line[1] == '\xBB' && line[2] == '\xBF') {
            line = line.substr(3);
        }
        stringstream ss(line);
        int number, volume;
        string chief, date, material;
        double cost;

        if (!(ss >> number >> chief >> date >> material >> volume >> cost)) {
            cerr << "Invalid line is missing: " << line << endl;
            continue;
        }

        Material m;
        m.push_back(date);
        m.push_back(material);
        m.push_back(to_string(volume));
        m.push_back(to_string(cost));

        brigades[number].first = chief;
        brigades[number].second.push_back(m);
        costs[number] += cost;
    }

    fin.close();
}

void writeSortedBrigades(const BrigadeMap& brigades, const map<int, double>& costs, const string& filename) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        throw runtime_error("Could not open file for writing.");
    }
    deque<int> keys;
    for (const auto& entry : brigades) {
        keys.push_back(entry.first);
    }
    sort(keys.begin(), keys.end(), greater<int>());

    for (int number : keys) {
        const auto& entry = brigades.at(number);
        const string& chief = entry.first;
        const deque<Material>& materials = entry.second;

        fout << "Brigade N " << number << " (" << chief << ") - total costs: " << costs.at(number) << "\n";

        for (const auto& mat : materials) {
            fout << "  " << mat[0] << " " << mat[1] << " " << mat[2] << " " << mat[3] << "\n";
        }

        fout << "\n";
    }

    fout.close();
}

void writeMinCostBrigades(const map<int, double>& costs, const BrigadeMap& brigades, const string& filename) {
    deque<pair<int, double>> sorted;
    for (const auto& entry : costs) {
        sorted.push_back(entry);
    }
    sort(sorted.begin(), sorted.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return a.second < b.second;
        });

    ofstream fout(filename);
    if (!fout.is_open()) {
        throw runtime_error("Could not open file for writing.");
    }
    fout << "3 brigades with the lowest costs:\n";
    for (size_t i = 0; i < 3 && i < sorted.size(); ++i) {
        int number = sorted[i].first;
        fout << "Brigade N " << number << " (" << brigades.at(number).first << ") - " << sorted[i].second << "\n";
    }

    fout.close();
}