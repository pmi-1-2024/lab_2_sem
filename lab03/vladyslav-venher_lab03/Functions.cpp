#include "Functions.h"

using namespace std;

void searchByName(Animal* animals[], int count, const string& searchName) {
    ofstream outputFile("output.txt", ios::app);
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (animals[i] && animals[i]->getName() == searchName) {
            outputFile << *animals[i];
            found = true;
        }
    }
    if (!found) {
        outputFile << "No animal found with the name: " << searchName << '\n';
    }
    outputFile.close();
}

void searchByYear(Animal* animals[], int count, int year) {
    ofstream outputFile("output.txt", ios::app);
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (animals[i] && animals[i]->getBirthYear() == year) {
            outputFile << *animals[i];
            found = true;
        }
    }
    if (!found) {
        outputFile << "No animals found from year: " << year << '\n';
    }
    outputFile.close();
}

void searchWhiteHorses(Animal* animals[], int count) {
    ofstream outputFile("output.txt", ios::app);
    bool found = false;
    for (int i = 0; i < count; ++i) {
        Horse* horse = dynamic_cast<Horse*>(animals[i]);
        if (horse && horse->isWhiteHorse()) {
            outputFile << *horse;
            found = true;
        }
    }
    if (!found) {
        outputFile << "No white horses found.\n";
    }
    outputFile.close();
}

void searchShortDonkeys(Animal* animals[], int count) {
    ofstream outputFile("output.txt", ios::app);
    bool found = false;
    for (int i = 0; i < count; ++i) {
        Donkey* donkey = dynamic_cast<Donkey*>(animals[i]);
        if (donkey && donkey->isShortDonkey()) {
            outputFile << *donkey;
            found = true;
        }
    }
    if (!found) {
        outputFile << "No short donkeys found.\n";
    }
    outputFile.close();
}
