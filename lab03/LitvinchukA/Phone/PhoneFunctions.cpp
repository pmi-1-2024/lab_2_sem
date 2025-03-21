#include "PhoneFunctions.h"
#include <fstream>

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
        if (phones[i]->hasAnsweringMachine()) {
            file << *phones[i] << "\n";
        }
    }
}

void sortPhonesByPrice(Phone** phones, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (*phones[j + 1] < *phones[j]) {
                Phone* temp = phones[j];
                phones[j] = phones[j + 1];
                phones[j + 1] = temp;
            }
        }
    }
}

void readPhonesFromStream(ifstream& stream, Phone**& phones, int& count, int& capacity) {
    while (stream) {
        int type;
        if (!(stream >> type))
            break;
        Phone* p = nullptr;
        if (type == 1) {
            MobilePhone* mp = new MobilePhone();
            stream >> *mp;
            p = mp;
        }
        else if (type == 2) {
            RadioPhone* rp = new RadioPhone();
            stream >> *rp;
            p = rp;
        }
        else if (type == 3) {
            HybridPhone* hp = new HybridPhone();
            stream >> *hp;
            p = hp;
        }
        if (p) {
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
    }
}

void searchByBrand(const string& brand, Phone** phones, int count, const string& filename) {
    ofstream file(filename);
    for (int i = 0; i < count; ++i) {
        if (phones[i]->getBrand() == brand) {
            file << *phones[i] << "\n";
        }
    }
}