#include "Functions.h"
#include <fstream>
#include <iostream>
#include <algorithm>

void readData(const std::string& filename, std::deque<Brigade>& brigades) {
    std::ifstream fin(filename);
    if (!fin) throw std::runtime_error("Can't open file");

    int number;
    std::string foreman;
    Material mat;
    while (fin >> number >> foreman >> mat.date >> mat.name >> mat.volume >> mat.cost) {
        Brigade b{ number, foreman, {mat} };
        brigades.push_back(b);
    }
}

void sortByForeman(std::deque<Brigade>& brigades) {
    std::sort(brigades.begin(), brigades.end(),
        [](const Brigade& a, const Brigade& b) {
            return a.foreman < b.foreman;
        });
}

void mergeBrigades(std::deque<Brigade>& brigades) {
    std::deque<Brigade> merged;
    for (const auto& b : brigades) {
        auto it = std::find_if(merged.begin(), merged.end(), [&](const Brigade& m) {
            return m.number == b.number;
            });
        if (it != merged.end()) {
            it->materials.insert(it->materials.end(), b.materials.begin(), b.materials.end());
        }
        else {
            merged.push_back(b);
        }
    }
    brigades = std::move(merged);
}

void printAll(const std::deque<Brigade>& brigades, const std::string& filename) {
    std::ofstream fout(filename);
    for (const auto& b : brigades) {
        fout << "Brigade #" << b.number << " (" << b.foreman << "):\n";
        for (const auto& m : b.materials) {
            fout << "  " << m.date << " | " << m.name << " | " << m.volume << " | " << m.cost << "\n";
        }
        fout << "Total: " << b.totalCost() << "\n\n";
    }
}

void printBrigadeInfo(const std::deque<Brigade>& brigades, int brigadeNumber) {
    auto it = std::find_if(brigades.begin(), brigades.end(), [&](const Brigade& b) {
        return b.number == brigadeNumber;
        });

    if (it == brigades.end()) {
        std::cerr << "Brigade not found\n";
        return;
    }

    std::deque<Material> materials = it->materials;
    std::sort(materials.begin(), materials.end(), [](const Material& a, const Material& b) {
        return a.date < b.date;
        });

    std::string filename = "brigade_" + std::to_string(brigadeNumber) + ".txt";
    std::ofstream fout(filename);
    fout << "Brigade #" << it->number << " (" << it->foreman << "):\n";
    for (const auto& m : materials) {
        fout << m.date << " | " << m.name << " | " << m.volume << " | " << m.cost << "\n";
    }
    fout << "Total cost: " << it->totalCost() << "\n";
}
