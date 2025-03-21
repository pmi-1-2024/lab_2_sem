#include "Functions.h"
#include "VacuumCleaner.h"
#include "WashingMachine.h"
#include "Combine.h"
#include "UniversalHelper.h"
#include <iostream>
#include <fstream>

using namespace std;

int loadDevices(Electrodevice**& devices) {
    ifstream inputFile("devices.txt");
    if (!inputFile) {
        cout << "Error opening devices.txt!" << endl;
        return 0;
    }

    int count = 0;
    string type;
    while (inputFile >> type) count++;
    inputFile.clear();
    inputFile.seekg(0);

    devices = new Electrodevice * [count];
    for (int i = 0; i < count; ++i) {
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
        else if (type == "UniversalHelper") {
            devices[i] = new UniversalHelper();
        }
        inputFile >> *devices[i];
    }
    inputFile.close();
    return count;
}

void searchDevices(Electrodevice** devices, int n, int choice) {
    ofstream resultFile("results.txt");
    if (!resultFile) {
        cout << "Error creating results.txt!" << endl;
        return;
    }

    string searchBrand = "";
    int searchPrice = -1, searchVacuumPower = -1, searchPrograms = -1, searchVolume = -1, searchCombinePower = -1, searchFunctions = -1;
    string searchColor = "";

    if (choice == 1) {
        ifstream searchFile("search.txt");
        if (!searchFile) {
            cout << "Error opening search.txt!" << endl;
            return;
        }
        searchFile >> searchBrand >> searchPrice >> searchVacuumPower >> searchColor >> searchPrograms >> searchVolume >> searchCombinePower >> searchFunctions;
        searchFile.close();

       
        if (searchBrand == "any") searchBrand = "";
        if (searchColor == "any") searchColor = "";
    }
    else {
        cout << "Enter brand (or 'any' to skip): ";
        cin >> searchBrand;
        if (searchBrand == "any") searchBrand = "";

        cout << "Enter price (or -1 to skip): ";
        cin >> searchPrice;

        cout << "Enter vacuum power (or -1 to skip): ";
        cin >> searchVacuumPower;

        cout << "Enter color (or 'any' to skip): ";
        cin >> searchColor;
        if (searchColor == "any") searchColor = "";

        cout << "Enter washing programs (or -1 to skip): ";
        cin >> searchPrograms;

        cout << "Enter washing volume (or -1 to skip): ";
        cin >> searchVolume;

        cout << "Enter combine power (or -1 to skip): ";
        cin >> searchCombinePower;

        cout << "Enter functions (or -1 to skip): ";
        cin >> searchFunctions;
    }

    bool found = false;
    for (int i = 0; i < n; ++i) {
        bool matches = true;

   
        if (!searchBrand.empty() && devices[i]->getBrand() != searchBrand) matches = false;
        if (searchPrice != -1 && devices[i]->getPrice() != searchPrice) matches = false;

        if (matches) {
            resultFile << "\n";
            resultFile << *devices[i];
            resultFile << "\n";
            found = true;
        }
    }

    if (!found) resultFile << "No devices found." << endl;

    resultFile.close();
}
