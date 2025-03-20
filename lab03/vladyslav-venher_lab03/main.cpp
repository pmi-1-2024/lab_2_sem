#include "Horse.h"
#include "Donkey.h"
#include "HybridAnimal.h"
#include <fstream>

const int MAX_ANIMALS = 100;

istream& operator>>(istream& is, Animal*& animal) {
    int type;
    if (!(is >> type)) return is;

    if (type == 1) { // Horse
        string name, color, breed;
        int birthYear;
        if (is >> name >> birthYear >> color >> breed)
            animal = new Horse(name, birthYear, color, breed);
    }
    else if (type == 2) { // Donkey
        string name, donkeyType;
        int birthYear;
        double height;
        if (is >> name >> birthYear >> donkeyType >> height)
            animal = new Donkey(name, birthYear, donkeyType, height);
    }
    else if (type == 3) { // HybridAnimal
        string name, color, breed, donkeyType, hybridName;
        int birthYear;
        double height;
        if (is >> name >> birthYear >> color >> breed >> donkeyType >> height >> hybridName)
            animal = new HybridAnimal(name, birthYear, color, breed, donkeyType, height, hybridName);
    }
    return is;
}

void searchByName(Animal* animals[], int count, const string& searchName, ofstream& outputFile) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (animals[i] && animals[i]->getName() == searchName) {
            animals[i]->display(outputFile);
            outputFile.flush();
            found = true;
        }
    }
    if (!found) {
        outputFile << "No animal found with the name: " << searchName << '\n';
        outputFile.flush();
    }
}

void searchByYear(Animal* animals[], int count, int year, ofstream& outputFile) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (animals[i] && animals[i]->getBirthYear() == year) {
            animals[i]->display(outputFile);
            outputFile.flush();
            found = true;
        }
    }
    if (!found) {
        outputFile << "No animals found from year: " << year << '\n';
        outputFile.flush();
    }
}

void searchWhiteHorses(Animal* animals[], int count, ofstream& outputFile) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        Horse* horse = dynamic_cast<Horse*>(animals[i]);
        if (horse && horse->isWhiteHorse()) {
            horse->display(outputFile);
            outputFile.flush();
            found = true;
        }
    }
    if (!found) {
        outputFile << "No white horses found.\n";
        outputFile.flush();
    }
}

void searchShortDonkeys(Animal* animals[], int count, ofstream& outputFile) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        Donkey* donkey = dynamic_cast<Donkey*>(animals[i]);
        if (donkey && donkey->isShortDonkey()) {
            donkey->display(outputFile);
            outputFile.flush();
            found = true;
        }
    }
    if (!found) {
        outputFile << "No short donkeys found.\n";
        outputFile.flush();
    }
}

int main() {
    ifstream inputFile("animals.txt");
    ofstream outputFile("output.txt", ios::out);

    if (!inputFile) {
        cerr << "Error opening input file.\n";
        return 1;
    }
    else {
        cout << "File opened successfully.\n";
    }

    if (!outputFile) {
        cerr << "Error opening output file.\n";
        return 1;
    }

    Animal* animals[MAX_ANIMALS] = { nullptr };
    int count = 0;

    while (count < MAX_ANIMALS) {
        Animal* animal = nullptr;
        if (!(inputFile >> animal)) {
            delete animal;
            break;
        }
        if (animal) {
            animals[count++] = animal;
            cout << "Loaded animal: " << animal->getName() << '\n';
        }
    }

    int choice;
    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Search by name\n";
        cout << "2. Search by birth year\n";
        cout << "3. Search for white horses\n";
        cout << "4. Search for short donkeys\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string searchName;
            cout << "Enter name: ";
            cin >> searchName;
            searchByName(animals, count, searchName, outputFile);
        }
        else if (choice == 2) {
            int year;
            cout << "Enter birth year: ";
            cin >> year;
            searchByYear(animals, count, year, outputFile);
        }
        else if (choice == 3) {
            searchWhiteHorses(animals, count, outputFile);
        }
        else if (choice == 4) {
            searchShortDonkeys(animals, count, outputFile);
        }

    } while (choice != 5);

    for (int i = 0; i < count; ++i) {
        delete animals[i];
    }
    outputFile.close();
    return 0;
}