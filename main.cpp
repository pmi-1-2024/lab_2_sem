#include <iostream>
#include <fstream>
#include "MobilePhone.h"
#include "RadioPhone.h"
#include "HybridPhone.h"

using namespace std;



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
        else if (type == 3) phones[count] = new HybridPhone();
        else continue;

        inFile >> *phones[count];
        count++;
    }

    inFile.close();
}
void searchByPrice(Phone** phones, int count, double minPrice, const string& filename) {



    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    for (int i = 0; i < count; i++) {
        if (phones[i]->getPrice() >= minPrice) {
            outFile << *phones[i];
        }
    }
    outFile.close();
}

int main() {


    const int MAX_PHONES = 100;
    Phone* phones[MAX_PHONES];
    int count = 0;

    readData(phones, count, "input.txt");
    searchByPrice(phones, count, 500, "output.txt");

    for (int i = 0; i < count; i++) {
        delete phones[i];
    }

    return 0;
}
