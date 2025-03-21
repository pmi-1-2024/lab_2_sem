#include <iostream>
#include <fstream>
#include <algorithm>
#include "Electroprilad.h"
#include "VacuumCleaner.h"
#include "WashingMachine.h"
#include "Blender.h"

#define NUM_DEVICES 7

int main() {
    Electroprilad* devices[NUM_DEVICES];

    std::ifstream inFile("devices.txt");
    if (!inFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    for (int i = 0; i < NUM_DEVICES; ++i) {
        string type;
        inFile >> type;

        if (type == "VacuumCleaner") {
            devices[i] = new VacuumCleaner();
        }
        else if (type == "WashingMachine") {
            devices[i] = new WashingMachine();
        }
        else if (type == "Blender") {
            devices[i] = new Blender();
        }

        inFile >> *devices[i];
    }

    inFile.close();

    for (int i = 0; i < NUM_DEVICES; ++i) {
        cout << *devices[i] << endl;
    }

    std::ofstream outFile1("File1.txt");
    std::sort(devices, devices + NUM_DEVICES, [](Electroprilad* a, Electroprilad* b) {
        return *a < *b;
        });
    for (int i = 0; i < NUM_DEVICES; ++i) {
        outFile1 << *devices[i] << endl;
    }
    outFile1.close();

    std::ofstream outFile2("File2.txt");
    string targetBrand = "Philips";  // Наприклад, шукаємо всі Philips
    for (int i = 0; i < NUM_DEVICES; ++i) {
        if (devices[i]->GetFirm() == targetBrand) {
            outFile2 << *devices[i] << endl;
        }
    }
    outFile2.close();

    for (int i = 0; i < NUM_DEVICES; ++i) {
        delete devices[i];
    }

    return 0;
}
