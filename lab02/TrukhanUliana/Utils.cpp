#include "Utils.h"

void readFromFile(ifstream& file, HouseElectronic** electronics, int& count) {
    if (!file.is_open()) {
        cout << "Error: file didn`t open!" << endl;
        return;
    }
    count = 0;
    char ch;

    while (file >> ch && count < 7) {
        switch (ch) {
        case 'v':
            electronics[count] = new VacuumCleaner();
            break;
        case 'w':
            electronics[count] = new WashingMachine();
            break;
        case 'c':
            electronics[count] = new Combine();
            break;
        default:
            cout << "Unknown type: " << ch << endl;
            file.clear();
            file.ignore(numeric_limits<streamsize>::max(), '\n'); // ѕропуск решти р€дка
            continue;
        }
        if (!(file >> *electronics[count])) {
            cout << "Error reading data for element " << count << endl;
            delete electronics[count];
            electronics[count] = nullptr;
            continue;
        }

        count++;
    }
}

void sortByName(HouseElectronic** electronics, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (*electronics[j + 1] < *electronics[j]) {  // ¬икористовуЇмо перевантажений оператор <
                HouseElectronic* temp = electronics[j];
                electronics[j] = electronics[j + 1];
                electronics[j + 1] = temp;
            }
        }
    }
    cout << "After sorting:\n";
    for (int i = 0; i < count; i++) {
        cout << *electronics[i] << endl;
    }

}


void writeSorted(ofstream& file, HouseElectronic** electronics, int count) {
    if (!file.is_open()) {
        cout << "Error: file didnТt open!" << endl;
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
        cout << "Error: file didnТt open!" << endl;
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

