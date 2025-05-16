#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "Bills.h"
using namespace std;

int main() {
    vector<GasBill> gasBills;
    vector<WaterBill> waterBills;

    ifstream inFile("input.txt");
    if (!inFile.is_open()) {
        cerr << "Error: Cannot open file input.txt!" << endl;
        return 1;
    }

    try {
        char type;
        while (inFile >> type) {
            if (type == 'G') {
                GasBill gb;
                if (!(inFile >> gb.name >> gb.people >> gb.amount)) {
                    throw runtime_error("Invalid data in gas bill entry.");
                }
                gasBills.push_back(gb);
            }
            else if (type == 'W') {
                WaterBill wb;
                if (!(inFile >> wb.name >> wb.lastMeter >> wb.volume >> wb.amount)) {
                    throw runtime_error("Invalid data in water bill entry.");
                }
                waterBills.push_back(wb);
            }
            else {
                throw runtime_error("Unknown bill type in input file.");
            }
        }

        inFile.close();

        sort(gasBills.begin(), gasBills.end(), compareGas);
        sort(waterBills.begin(), waterBills.end(), compareWater);

        ofstream gasOut("gas_output.txt");
        cout << "=== Gas Bills (sorted by amount ascending) ===" << endl;
        for (const auto& g : gasBills) {
            cout << g.name << " | People: " << g.people << " | Amount: " << fixed << setprecision(2) << g.amount << endl;
            gasOut << g.name << " " << g.people << " " << g.amount << endl;
        }
        gasOut.close();

        ofstream waterOut("water_output.txt");
        cout << "\n=== Water Bills (sorted by volume descending) ===" << endl;
        for (const auto& w : waterBills) {
            cout << w.name << " | Meter: " << w.lastMeter << " | Volume: " << w.volume
                << " | Amount: " << fixed << setprecision(2) << w.amount << endl;
            waterOut << w.name << " " << w.lastMeter << " " << w.volume << " " << w.amount << endl;
        }
        waterOut.close();

        double totalGasForOnePerson = 0;
        int onePersonCount = 0;
        for (const auto& g : gasBills) {
            if (g.people == 1) {
                totalGasForOnePerson += g.amount;
                onePersonCount++;
            }
        }

        cout << "\nTotal gas amount paid by subscribers with 1 registered person: " << totalGasForOnePerson << endl;
        cout << "Number of such subscribers: " << onePersonCount << endl;
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return 2;
    }

    return 0;
}
