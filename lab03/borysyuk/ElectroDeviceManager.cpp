#include "ElectroDeviceManager.h"

ElectroDeviceManager::ElectroDeviceManager(int s) : size(s) {
    devices = new ElectroDevice * [size];
}

ElectroDeviceManager::~ElectroDeviceManager() {
    for (int i = 0; i < size; i++) {
        delete devices[i];
    }
    delete[] devices;
}

ElectroDeviceManager::ElectroDeviceManager(const ElectroDeviceManager& other) : size(other.size) {
    devices = new ElectroDevice * [size];

    for (int i = 0; i < size; i++) {
        if (dynamic_cast<VacuumCleaner*>(other.devices[i])) {
            devices[i] = new VacuumCleaner(*dynamic_cast<VacuumCleaner*>(other.devices[i]));
        }
        else if (dynamic_cast<WashingMachine*>(other.devices[i])) {
            devices[i] = new WashingMachine(*dynamic_cast<WashingMachine*>(other.devices[i]));
        }
        else if (dynamic_cast<FoodProcessor*>(other.devices[i])) {
            devices[i] = new FoodProcessor(*dynamic_cast<FoodProcessor*>(other.devices[i]));
        }
    }
}


ElectroDeviceManager& ElectroDeviceManager::operator=(const ElectroDeviceManager& other) {
    if (this != &other) {  
       
        for (int i = 0; i < size; i++) {
            delete devices[i];
        }
        delete[] devices;

        
        size = other.size;
        devices = new ElectroDevice * [size];

        for (int i = 0; i < size; i++) {
            if (dynamic_cast<VacuumCleaner*>(other.devices[i])) {
                devices[i] = new VacuumCleaner(*dynamic_cast<VacuumCleaner*>(other.devices[i]));
            }
            else if (dynamic_cast<WashingMachine*>(other.devices[i])) {
                devices[i] = new WashingMachine(*dynamic_cast<WashingMachine*>(other.devices[i]));
            }
            else if (dynamic_cast<FoodProcessor*>(other.devices[i])) {
                devices[i] = new FoodProcessor(*dynamic_cast<FoodProcessor*>(other.devices[i]));
            }
            else if (dynamic_cast<ExtraDevice*>(other.devices[i])) {
                devices[i] = new ExtraDevice(*dynamic_cast<ExtraDevice*>(other.devices[i]));
            }
        }
    }
    return *this;
}

ElectroDevice& ElectroDeviceManager::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("index out");
    }
    return *devices[index];
}


void ElectroDeviceManager::readFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Error file" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        string type;
        fin >> type;

        if (type == "Vacuum") devices[i] = new VacuumCleaner();
        else if (type == "Washing") devices[i] = new WashingMachine();
        else if (type == "FoodProcessor") devices[i] = new FoodProcessor();
        else if (type == "Extra") devices[i] = new ExtraDevice();

        fin >> *devices[i];
    }
    fin.close();
}

void ElectroDeviceManager::writeSortedToFile(const string& filename) {
    ofstream fout(filename);
    if (!fout) {
        cout << "Error file" << endl;
        return;
    }

    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (devices[j]->getName() > devices[j + 1]->getName()) {
                ElectroDevice* temp = devices[j];
                devices[j] = devices[j + 1];
                devices[j + 1] = temp;
            }
        }
    }

    
    int count = 1;
    for (int i = 0; i < size; i++) {
        if (i < size - 1 && devices[i]->getName() == devices[i + 1]->getName()) {
            count++;
        }
        else {
            fout << "Name: " << devices[i]->getName() << ", Counts: " << count << endl;
            count = 1;
        }
    }

    fout.close();
}

void ElectroDeviceManager::filterByBrandAndWrite(const string& filename, const string& brand) {
    ofstream fout(filename);
    if (!fout) {
        cout << "Error file" << endl;
        return;
    }

    double totalCost = 0;
    int count = 0;

    fout << "List of company devices " << brand << ":" << endl;

    for (int i = 0; i < size; i++) {
        if (devices[i]->getBrand() == brand) {
            fout << devices[i]->getName() << endl;
            totalCost += devices[i]->getPrice();
            count++;
        }
    }

    if (count == 0) {
        fout << "Devices of this company were not found!" << endl;
    }
    else {
        fout << "Total cost: " << totalCost << " grn" << endl;
    }

    fout.close();
}