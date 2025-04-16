#include <iostream>
#include <fstream>
#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"
#include "HybridPhone.h"

using namespace std;

Phone* createPhone(const string& type) {
    if (type == "Mobile") return new MobilePhone();
    if (type == "Radio") return new RadioPhone();
    if (type == "Hybrid") return new HybridPhone();
    return nullptr;
}

void readPhones(ifstream& file, Phone** phones, int count, int offset) {
    for (int i = 0; i < count; i++) {
        string type;
        file >> type;
        phones[offset + i] = createPhone(type);
        if (phones[offset + i]) file >> *phones[offset + i];
    }
}

void sortPhones(Phone** phones, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*phones[j] > *phones[j + 1]) {
                Phone* temp = phones[j];
                phones[j] = phones[j + 1];
                phones[j + 1] = temp;
            }
        }
    }
}

int calculateTotalPrice(Phone** phones, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += phones[i]->getPrice();
    }
    return sum;
}

int main() {
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");

    int count1 = 0, count2 = 0;
    file1 >> count1;
    file2 >> count2;

    Phone** phones = new Phone * [count1 + count2];

    readPhones(file1, phones, count1, 0);
    readPhones(file2, phones, count2, count1);

    sortPhones(phones, count1 + count2);

    ofstream file3("file3.txt");
    for (int i = 0; i < count1 + count2; i++) {
        file3 << *phones[i] << endl;
    }

    file3 << calculateTotalPrice(phones, count1 + count2) << endl;

    for (int i = 0; i < count1 + count2; i++) {
        RadioPhone* rp = dynamic_cast<RadioPhone*>(phones[i]);
        if (rp && rp->getAnsweringMachine()) {
            file3 << *phones[i] << endl;
        }
    }

    file1.close();
    file2.close();
    file3.close();

    for (int i = 0; i < count1 + count2; i++) {
        delete phones[i];
    }
    delete[] phones;

    return 0;
}
