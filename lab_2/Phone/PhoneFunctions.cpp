#include "PhoneFunctions.h"
#include "RadioPhone.h"
#include <fstream>

void readPhonesFromFile(const string& filename, Phone**& phones, int& count, int& capacity) {
    ifstream file(filename);
    if (!file) return;
    while (file) {
        Phone* p = nullptr;
        if (file >> p) {
            if (count >= capacity) {
                int newCapacity = capacity * 2;
                Phone** newPhones = new Phone * [newCapacity];
                for (int i = 0; i < count; i++) {
                    newPhones[i] = phones[i];
                }
                delete[] phones;
                phones = newPhones;
                capacity = newCapacity;
            }
            phones[count++] = p;
        }
        else {
            break;
        }
    }
}

void writePhonesToFile(const string& filename, Phone** phones, int count) {
    ofstream file(filename);
    double totalSum = 0;
    for (int i = 0; i < count; ++i) {
        file << *phones[i] << "\n";
        totalSum += phones[i]->getPrice();
    }
    file << "Total sum: " << totalSum << "\n";
}

void writeRPWithAMToFile(const string& filename, Phone** phones, int count) {
    ofstream file(filename);
    for (int i = 0; i < count; ++i) {
        RadioPhone* radioPhone = dynamic_cast<RadioPhone*>(phones[i]);
        if (radioPhone && radioPhone->getHasAnsweringMachine()) {
            file << *radioPhone << "\n";
        }
    }
}

void sortPhonesByPrice(Phone** phones, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (phones[j]->getPrice() > phones[j + 1]->getPrice()) {
                Phone* temp = phones[j];
                phones[j] = phones[j + 1];
                phones[j + 1] = temp;
            }
        }
    }
}