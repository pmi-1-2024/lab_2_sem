#include <iostream>
#include <fstream>
#include "VacuumCleaner.h"
#include "WashingMachine.h"
#include "Combine.h"
#include "Sort.h"

using namespace std;

int main() {
    int n = 7;
    Electrodevice** devices = new Electrodevice * [n];

    ifstream inputFile("devices.txt");
    if (!inputFile) {
        cout << "Error opening devices.txt!" << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        string type;
        inputFile >> type;
        if (type == "Vacuum") {
            devices[i] = new VacuumCleaner();
        }
        else if (type == "WashingMachine") {
            devices[i] = new WashingMachine();
        }
        else if (type == "Combine") {
            devices[i] = new Combine();
        }
        inputFile >> *devices[i];
    }
    inputFile.close();

    ofstream file1("File1.txt");
    ofstream file2("File2.txt");
    if (!file1 || !file2) {
        cout << "Error creating output files!" << endl;
        return 1;
    }

    int totalCost = 0;
    int vacuumCount = 0, washingMachineCount = 0, combineCount = 0;

    file2 << "List of device names:\n";

    sortDevices(devices, n);

    for (int i = 0; i < n; ++i) {
        file1 << *devices[i] << "\n";
        file2 << devices[i]->getBrand() << "\n";

        if (dynamic_cast<VacuumCleaner*>(devices[i])) vacuumCount++;
        else if (dynamic_cast<WashingMachine*>(devices[i])) washingMachineCount++;
        else if (dynamic_cast<Combine*>(devices[i])) combineCount++;

        totalCost += devices[i]->getPrice();
    }

    file2 << "\nTotal cost: " << totalCost << " UAH\n\n";

    file1 << "Total number of devices: " << n << "\nVacuum Cleaners: " << vacuumCount
        << "\nWashing Machines: " << washingMachineCount
        << "\nCombines: " << combineCount << "\n";

    file1.close();
    file2.close();

    for (int i = 0; i < n; ++i) delete devices[i];
    delete[] devices;

    cout << "Files created successfully!\n";
    return 0;
}
