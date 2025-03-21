#include "Phone.h"

void readData(Phone** phones, int& count, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    count = 0;
    int type;
    while (inFile >> type) {
        if (type == 1) phones[count] = new MobilePhone();
        else if (type == 2) phones[count] = new RadioPhone();
        else continue;

        inFile >> *phones[count];
        count++;
    }

    inFile.close();
}

void writeSortedPhones(Phone** phones, int count, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (phones[i]->getPrice() > phones[j]->getPrice()) {
                swap(phones[i], phones[j]);
            }
        }
    }

    double totalPrice = 0;
    for (int i = 0; i < count; i++) {
        outFile << *phones[i];
        totalPrice += phones[i]->getPrice();
    }
    outFile << "Total price: " << totalPrice << endl;

    outFile.close();
}

void writeRadioWithAnsweringMachine(Phone** phones, int count, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        if (dynamic_cast<RadioPhone*>(phones[i]) && phones[i]->hasAnsweringMachine()) {
            outFile << *phones[i];
        }
    }

    outFile.close();
}

int main() {
    const int MAX_PHONES = 100;
    Phone* phones[MAX_PHONES];
    int count = 0;

    readData(phones, count, "input1.txt");
    int count2 = 0;
    readData(phones + count, count2, "input2.txt");
    count += count2;

    writeSortedPhones(phones, count, "sorted_phones.txt");
    writeRadioWithAnsweringMachine(phones, count, "radio_with_answering_machine.txt");

    for (int i = 0; i < count; i++) {
        delete phones[i];
    }

    return 0;
}
