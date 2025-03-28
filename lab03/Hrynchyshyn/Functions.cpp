#include "Functions.h"
#include "VacuumCleaner.h"
#include "WashingMachine.h"
#include "Combine.h"
#include "UniversalHelper.h"
#include <iostream>
#include <fstream>
#include <string>
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
        if (devices[i]) {
            inputFile >> *devices[i];
        }
        else {
            cout << "Unknown device type: " << type << endl;
            delete[] devices;
            inputFile.close();
            return 0;
        }
    }
    inputFile.close();
    return count;
}

void searchDevices(Electrodevice** devices, int n) {
    ofstream resultFile("results.txt");
    if (!resultFile) {
        cout << "Error creating results.txt!" << endl;
        return;
    }

    string searchBrand = "";
    int searchPrice = -1;
    int searchVacuumPower = -1;
    string searchColor = "";
    int searchPrograms = -1;
    int searchVolume = -1;
    int searchCombinePower = -1;
    int searchFunctions = -1;


    ifstream searchFile("search.txt");
    if (!searchFile) {
        cout << "Error opening search.txt!" << endl;
        resultFile << "Error opening search.txt!" << endl;
        resultFile.close();
        return;
    }
    searchFile >> searchBrand >> searchPrice >> searchVacuumPower >> searchColor >> searchPrograms >> searchVolume >> searchCombinePower >> searchFunctions;
    searchFile.close();

    if (searchBrand == "any") searchBrand = "";
    if (searchColor == "any") searchColor = "";

    bool found = false;
    for (int i = 0; i < n; ++i) {
        bool matches = true;

        if (!searchBrand.empty() && devices[i]->getBrand() != searchBrand) matches = false;
        if (searchPrice != -1 && devices[i]->getPrice() != searchPrice) matches = false;

        if (VacuumCleaner* vc = dynamic_cast<VacuumCleaner*>(devices[i])) {
            if (searchVacuumPower != -1 && vc->getPower() != searchVacuumPower) matches = false;
            if (!searchColor.empty() && vc->getColor() != searchColor) matches = false;
        }
        if (WashingMachine* wm = dynamic_cast<WashingMachine*>(devices[i])) {
            if (searchPrograms != -1 && wm->getPrograms() != searchPrograms) matches = false;
            if (searchVolume != -1 && wm->getVolume() != searchVolume) matches = false;
        }
        if (Combine* cb = dynamic_cast<Combine*>(devices[i])) {
            if (searchCombinePower != -1 && cb->getCombinePower() != searchCombinePower) matches = false;
            if (searchFunctions != -1 && cb->getFunctions() != searchFunctions) matches = false;
        }
        if (UniversalHelper* uh = dynamic_cast<UniversalHelper*>(devices[i])) {
            if (searchVacuumPower != -1 && uh->VacuumCleaner::getPower() != searchVacuumPower) matches = false;
            if (!searchColor.empty() && uh->VacuumCleaner::getColor() != searchColor) matches = false;
            if (searchPrograms != -1 && uh->WashingMachine::getPrograms() != searchPrograms) matches = false;
            if (searchVolume != -1 && uh->WashingMachine::getVolume() != searchVolume) matches = false;
            if (searchCombinePower != -1 && uh->Combine::getCombinePower() != searchCombinePower) matches = false;
            if (searchFunctions != -1 && uh->Combine::getFunctions() != searchFunctions) matches = false;
        }

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
