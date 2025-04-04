#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"
#include "MySort.h"
#include <fstream>
#include <iostream>


int main() {
    ifstream file1("phones1.txt");
    ifstream file2("phones2.txt");
    ofstream output("res.txt");

    if (!file1 || !file2 || !output) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int size = 0;
    Phone** phones = new Phone * [100];
    int type;

    while (file1 >> type) {
        if (type == 1)
            phones[size] = new MobilePhone;
        else if (type == 2)
            phones[size] = new RadioPhone;
        file1 >> *phones[size];
        size++;
    }
    while (file2 >> type) {
        if (type == 1)
            phones[size] = new MobilePhone;
        else if (type == 2)
            phones[size] = new RadioPhone;
        file2 >> *phones[size];
        size++;
    }

    mySort(phones, phones + size, [](Phone* a, Phone* b) { return a->getPrice() < b->getPrice(); });
    double totalCost = 0;
    for (int i = 0; i < size; i++) {
        output << *phones[i];
        totalCost += phones[i]->getPrice();
    }
    output << "Total cost: " << totalCost << endl;

    output << endl << "Phones with answering machine:\n";
    for (int i = 0; i < size; i++) {
        RadioPhone* rp = dynamic_cast<RadioPhone*>(phones[i]);
        if (rp && rp->hasAnsweringMachine()) {
            output << *phones[i];
        }
    }

    if (phones) {
        for (int i = 0; i < size; i++) {
            delete phones[i];
        }
        delete[] phones;
    }
    return 0;
}
