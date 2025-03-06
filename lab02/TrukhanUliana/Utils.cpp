#include "Utils.h"

void readFromFile(ifstream& file, HouseElectronic** electronics, int& count) {
    if (!file.is_open()) {
        cout << "Error: file didn`t open!" << endl;
        return;
    }

    count = 0;
    string name;
    while (file >> name && count < 7) {
        string firm;
        double price;

        if (name == "VacuumCleaner") {
            int power;
            string color;
            file >> firm >> price >> power >> color;
            electronics[count++] = new VacuumCleaner(name, firm, price, power, color);
        }
        else if (name == "WashingMachine") {
            int programs, volume;
            file >> firm >> price >> programs >> volume;
            electronics[count++] = new WashingMachine(name, firm, price, programs, volume);
        }
        else if (name == "Combine") {
            int power, functions;
            file >> firm >> price >> power >> functions;
            electronics[count++] = new Combine(name, firm, price, power, functions);
        }
    }

}


void sortByName(HouseElectronic** electronics, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (electronics[j]->getName() > electronics[j+1]->getName()) {
                HouseElectronic* temp = electronics[j];
                electronics[j] = electronics[j + 1];
                electronics[j + 1] = temp;
            }
        }
    }
    cout << "After sorting:\n";
    for (int i = 0; i < count; i++) {
        cout << electronics[i]->getName() << " | " << *electronics[i] << endl;
    }

}

void writeSorted(ofstream& file, HouseElectronic** electronics, int count) {
    if (!file.is_open()) {
        cout << "Error: file didn’t open!" << endl;
        return;
    }
    sortByName(electronics, count);

    for (int i = 0; i < count; i++) {
        file << *electronics[i] << endl;
    }
    file << "Total: " << count << endl;
}

void writeFirmToFile(ofstream& file, HouseElectronic** electronics, int count, const string& firm) {
    if (!file.is_open()) {
        cout << "Error: file didn’t open!" << endl;
        return;
    }

    double totalPrice = 0;
    for (int i = 0; i < count; i++) {
        if (electronics[i]->getFirm() == firm) {
            file << electronics[i]->getName() << endl;
            totalPrice += electronics[i]->getPrice();
        }
    }
    cout << "Total price: " << totalPrice;
    file << "Total price: " << totalPrice << endl;
}

