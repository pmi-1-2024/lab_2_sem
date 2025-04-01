#include <iostream>
#include <fstream>
#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"

using namespace std;

void readPhones(ifstream& file, Phone** phones, int& index, int count) {
    for (int i = 0; i < count; i++, index++) {
        string type;
        file >> type;
        if (type == "Mobile") {
            phones[index] = new MobilePhone();
        }
        else if (type == "Radio") {
            phones[index] = new RadioPhone();
        }
        file >> *phones[index];
    }
}

int main() {
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");

    int count1 = 0, count2 = 0;
    file1 >> count1;
    file2 >> count2;

    Phone** phones = new Phone * [count1 + count2];
    int index = 0;

    readPhones(file1, phones, index, count1);
    readPhones(file2, phones, index, count2);

    for (int i = 0; i < count1 + count2 - 1; i++) {
        for (int j = 0; j < count1 + count2 - i - 1; j++) {
            if (*phones[j] > *phones[j + 1]) {
                Phone* temp = phones[j];
                phones[j] = phones[j + 1];
                phones[j + 1] = temp;
            }
        }
    }

    ofstream file3("file3.txt");
    for (int i = 0; i < count1 + count2; i++) {
        file3 << *phones[i] << endl;
    }

    int sum = 0;
    for (int i = 0; i < count1 + count2; i++) {
        sum += phones[i]->getPrice();
    }
    file3 << sum << endl;

    for (int i = 0; i < count1 + count2; i++) {
        if (auto* radioPhone = dynamic_cast<RadioPhone*>(phones[i])) {
            if (radioPhone->getAnsweringMachine()) {
                file3 << *phones[i] << endl;
            }
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
