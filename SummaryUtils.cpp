#include "SummaryUtils.h"
#include <fstream>
#include <iomanip>
#include <stdexcept>

void summarizeMaterials(const map<int, TeamData>& merged, map<string, MaterialSummary>& summary) {
    for (const auto& [_, team] : merged) {
        for (const auto& m : team.materials) {
            summary[m.name].totalVolume += m.volume;
            summary[m.name].totalCost += m.cost;
        }
    }
}

void saveSummaryToFile(const map<string, MaterialSummary>& summary, const string& filename) {
    ofstream fout(filename);
    if (!fout.is_open()) throw runtime_error("Cannot open summary file: " + filename);

    fout << "Material Summary:\n";
    for (const auto& [name, data] : summary) {
        fout << name << ": " << fixed << setprecision(2)
            << data.totalVolume << " m3, $" << data.totalCost << endl;
    }
}
