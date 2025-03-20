#pragma once

#include "ElectroDevice.h"
#include "VacuumCleaner.h"
#include "WashingMachine.h"
#include "FoodProcessor.h"

class ElectroDeviceManager {
private:
    ElectroDevice** devices;
    int size;

public:
    ElectroDeviceManager(int s);
    ~ElectroDeviceManager();

    ElectroDeviceManager(const ElectroDeviceManager& other);
    ElectroDeviceManager& operator=(const ElectroDeviceManager& other);

    ElectroDevice& operator[](int index);
    

    void readFromFile(const string& filename);
    void writeSortedToFile(const string& filename);
    void filterByBrandAndWrite(const string& filename, const string& brand);
};