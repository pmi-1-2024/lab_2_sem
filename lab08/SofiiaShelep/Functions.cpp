#include "Functions.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <stdexcept>
using namespace std;

void readFromFile(const string& filename, list<Brigade>& brigades) {
    ifstream in(filename);
    if (!in)
        throw runtime_error("Не вдалося відкрити файл для читання.");

    int number;
    string foreman, date, material;
    double volume, cost;

    while (in >> number >> foreman >> date >> material >> volume >> cost) {
        Expense e{ date, material, volume, cost };

        auto it = find_if(brigades.begin(), brigades.end(),
            [&](const Brigade& b) { return b.number == number && b.foreman == foreman; });

        if (it != brigades.end()) {
            it->expenses.push_back(e);
        }
        else {
            Brigade b{ number, foreman, {e} };
            brigades.push_back(b);
        }
    }
}

void sortBrigades(list<Brigade>& brigades) {
    brigades.sort();
}

void printBrigades(const list<Brigade>& brigades, const string& outFile) {
    ofstream out(outFile);
    if (!out)
        throw runtime_error("Не вдалося відкрити файл для запису.");

    for (const auto& b : brigades) {
        out << b << endl;
    }
}

double printTotalCosts(const list<Brigade>& brigades, const string& outFile) {
    ofstream out(outFile);
    if (!out)
        throw runtime_error("Не вдалося відкрити файл для запису.");

    double total = 0.0;
    for (const auto& b : brigades) {
        double brigadeTotal = b.totalCost();
        total += brigadeTotal;
        out << "Brigade #" << b.number << ", Foreman: " << b.foreman
            << " - Total Cost: " << fixed << setprecision(2) << brigadeTotal << endl;
    }

    return total;
}

double getTotalForAllBrigades(const list<Brigade>& brigades) {
    return accumulate(
        brigades.begin(), brigades.end(), 0.0,
        [](double sum, const Brigade& b) {
            return sum + b.totalCost();
        }
    );
}