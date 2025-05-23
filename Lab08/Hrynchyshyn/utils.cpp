#include "utils.h" 
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void ReadFile(ifstream& file, map<int, Brigade>& brigades) {
    if (!file.is_open()) {
        throw runtime_error("Cannot open file.");
    }

    string line;
    while (getline(file, line)) {
        try {
            stringstream ss(line);
            int number;
            string foreman, date, name;
            double volume, cost;

            if (!(ss >> number >> foreman >> date >> name >> volume >> cost)) {
                throw runtime_error("Invalid data format in line: " + line);
            }

            Material m(date, name, volume, cost);

            auto it = brigades.find(number);
            if (it != brigades.end()) {
                it->second.addMaterial(m);
            }
            else {
                Brigade b(number, foreman);
                b.addMaterial(m);
                brigades[number] = b;
            }
        }
        catch (const exception& e) {
            cerr << "Error reading line: " << line << "\n" << e.what() << endl;
        }
    }
}

void outputSortedByForeman(const map<int, Brigade>& brigades, const string& filename) {
    vector<Brigade> sorted;
    for (const auto& pair : brigades)
        sorted.push_back(pair.second);

    sort(sorted.begin(), sorted.end(), compareByForeman);

    ofstream out(filename);
    if (!out)
        throw runtime_error("Cannot open file for writing: " + filename);

    for (const auto& b : sorted)
        b.printMaterials(out);

    out.close();

    for (const auto& b : sorted)
        b.printMaterials(cout);
}

void outputBrigadeByDate(const map<int, Brigade>& brigades, int number, const string& filename) {
    ofstream out(filename);
    if (!out)
        throw runtime_error("Cannot open file for writing: " + filename);

    auto it = brigades.find(number);
    if (it == brigades.end())
        throw invalid_argument("Brigade not found: " + to_string(number));

    it->second.printSortedByDate(out);
    it->second.printSortedByDate(cout);

    out.close();
}
