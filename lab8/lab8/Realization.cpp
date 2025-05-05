#include "Realization.h"
#include "Rahunok.h"
#include "R_Gas.h"
#include "R_Water.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool compareByPaidAmount(GasRah* a, GasRah* b) {
    return a->getPaidAmount() < b->getPaidAmount();
}

void readFromFile(deque<Rahunok*>& rahunoki) {
    ifstream file("AllData.txt");
    if (!file.is_open()) {
        throw runtime_error("Can't open main file for reading");
    }

    char type;
    while (file >> type) {
        Rahunok* rahunok = nullptr;
        try {
            if (type == 'g') {
                rahunok = new GasRah();
            }
            else if (type == 'w') {
                rahunok = new WaterRah();
            }
            else {
                throw runtime_error("Unknown type of bill");
            }

            file >> *rahunok;
            rahunoki.push_back(rahunok);
        }
        catch (const runtime_error& e) {
            cerr << "Error: " << e.what() << endl;
            delete rahunok;
        }
    }

    file.close();
}

void showAllBills(const deque<Rahunok*>& rahunoki) {
    if (rahunoki.empty()) {
        throw runtime_error("No bills available to display!");
    }

    cout << "\nAll Bills:\n";
    for (const auto& bill : rahunoki) {
        if (bill) {
            cout << bill->getType() << " bill, " << *bill << endl;
        }
        else {
            cerr << "Error: Null bill encountered!" << endl;
        }
    }
}

void showGasBills(const deque<Rahunok*>& rahunoki) {
    cout << "\nGas Bills (sorted by sum):\n";
    deque<GasRah*> gasList;

    for (auto bill : rahunoki) {
        if (auto gas = dynamic_cast<GasRah*>(bill)) {
            gasList.push_back(gas);
        }
    }

    if (gasList.empty()) {
        throw runtime_error("No gas bills available to display!");
    }
    
    sort(gasList.begin(), gasList.end(), compareByPaidAmount);

    for (auto gas : gasList) {
        cout << *gas << endl;
    }
}

void saveToFiles(const deque<Rahunok*>& rahunoki) {
    ofstream gasFile("Gas_Paid.txt");
    ofstream waterFile("Water_Paid.txt");

    if (!gasFile.is_open() || !waterFile.is_open()) {
        throw runtime_error("Can't open output files!");
    }

    deque<GasRah*> gasList;
    deque<WaterRah*> waterList;

    for (auto bill : rahunoki) {
        if (auto gas = dynamic_cast<GasRah*>(bill)) {
            gasList.push_back(gas);
        }
        else if (auto water = dynamic_cast<WaterRah*>(bill)) {
            waterList.push_back(water);
        }
    }

    if (gasList.empty() && waterList.empty()) {
        throw runtime_error("No bills to save!");
    }

    sort(gasList.begin(), gasList.end(), [](GasRah* a, GasRah* b) {
        return a->getPaidAmount() < b->getPaidAmount();
        });

    sort(waterList.begin(), waterList.end(), [](WaterRah* a, WaterRah* b) {
        return a->getPaidVolume() > b->getPaidVolume(); 
        });

    for (auto gas : gasList) {
        gasFile << *gas << endl;
    }

    for (auto water : waterList) {
        waterFile << *water << endl;
    }

    gasFile.close();
    waterFile.close();
}

void showGasStats(const deque<Rahunok*>& rahunoki) {
    double totalGasPaid = 0.0;
    int singlePersonCount = 0;

    for (auto r : rahunoki) {
        if (r->getType() == "Gas") {
            const GasRah* gasBill = dynamic_cast<const GasRah*>(r);
            if (gasBill) {
                if (gasBill->getPeople() == 1) {
                    totalGasPaid += gasBill->getPaidAmount();
                    singlePersonCount++;
                }
            }
        }
    }

    if (singlePersonCount == 0) {
        throw runtime_error("No gas bills with 1 person found!");
    }

    ofstream soloGasFile("Solo_Gas.txt");
    if (!soloGasFile.is_open()) {
        throw runtime_error("Can't open Solo_Gas.txt for writing!");
    }

    soloGasFile << "Total sum paid for gas: " << totalGasPaid << endl;
    soloGasFile << "Number of accounts with 1 person: " << singlePersonCount << endl;
    soloGasFile.close();

    cout << "\nTotal sum paid for gas: " << totalGasPaid << endl;
    cout << "Number of accounts with 1 person: " << singlePersonCount << endl;
}

