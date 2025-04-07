#include "Horse.h"
#include "Donkey.h"
#include "Mule.h"
#include <fstream>
#include <iostream>
#include <algorithm> 

using namespace std;

const int MAX_ANIMALS = 100;

int main() {
    ifstream inputFile("animals.txt");
    ofstream file1("File1.txt"), file2("File2.txt");

    if (!inputFile) {
        cerr << "Error opening input file.\n";
        return 1;
    }

    Animal* animals[MAX_ANIMALS];
    int count = 0;


    while (count < MAX_ANIMALS && inputFile.peek() != EOF) {
        int type;
        inputFile >> type;

        Animal* animal = nullptr;

        if (type == 1) animal = new Horse;
        else if (type == 2) animal = new Donkey;
        else if (type == 3) animal = new Mule;

        if (animal) {
            inputFile >> *animal;
            animals[count++] = animal;
        }
    }


    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (animals[j]->getBirthYear() > animals[j + 1]->getBirthYear()) {
                swap(animals[j], animals[j + 1]);
            }
        }
    }


    for (int i = 0; i < count; ++i)
        file1 << *animals[i];

    int whiteHorses = 0, shortDonkeys = 0;


    for (int i = 0; i < count; ++i) {
        if (dynamic_cast<Mule*>(animals[i]) != nullptr) {
            continue; 
        }

        if (animals[i]->isWhiteHorse()) {
            file2 << *animals[i];
            ++whiteHorses;
        }

        if (animals[i]->isShortDonkey()) {
            file2 << *animals[i];
            ++shortDonkeys;
        }
    }


    file2 << "White Horses: " << whiteHorses << '\n';
    file2 << "Short Donkeys: " << shortDonkeys << '\n';


    for (int i = 0; i < count; ++i)
        delete animals[i];

    return 0;
}
