#include "Horse.h"
#include "Donkey.h"
#include "Mule.h"
#include "HybridRobotDonkey.h"
#include <fstream>
#include <iostream>

using namespace std;

const int MAX_ANIMALS = 100;


istream& operator>>(istream& is, Animal*& animal) {
    int type;
    is >> type;
    if (type == 1) { // Horse
        string name, color, breed;
        int birthYear;
        is >> name >> birthYear >> color >> breed;
        animal = new Horse(name, birthYear, color, breed);
    }
    else if (type == 2) { // Donkey
        string name, type;
        int birthYear;
        double height;
        is >> name >> birthYear >> type >> height;
        animal = new Donkey(name, birthYear, type, height);
    }
    else if (type == 3) { // Mule
        string name, color, breed, type, nickname;
        int birthYear;
        double height;
        is >> name >> birthYear >> color >> breed >> type >> height >> nickname;
        animal = new Mule(name, birthYear, color, breed, type, height, nickname);
    }
    else if (type == 4) { // HybridRobotDonkey
        string name, color, breed, type, nickname, robotFunctionality;
        int birthYear;
        double height;
        is >> name >> birthYear >> color >> breed >> type >> height >> nickname >> robotFunctionality;
        animal = new HybridRobotDonkey(name, birthYear, color, breed, type, height, nickname, robotFunctionality);
    }
    return is;
}

void interactiveSearch(Animal* animals[], int count) {
    string parameter;
    cout << "\nEnter a parameter for search (e.g., 'white', 'HybridCleaning', etc.): ";
    cin >> parameter;

    bool found = false;
    cout << "\nSearch results:\n";
    for (int i = 0; i < count; ++i) {
        if (animals[i]->matchesCriteria(parameter)) {
            animals[i]->display(cout);
            found = true;
        }
    }

    if (!found) {
        cout << "No animals found matching the parameter '" << parameter << "'.\n";
    }
}


void demonstrateRobotFunctionality(Animal* animals[], int count) {
    cout << "\nDemonstrating HybridRobotDonkey functionality:\n";
    bool hasRobotDonkeys = false;

    for (int i = 0; i < count; ++i) {
        auto* robotDonkey = dynamic_cast<HybridRobotDonkey*>(animals[i]);
        if (robotDonkey != nullptr) {
            hasRobotDonkeys = true;
            cout << "HybridRobotDonkey Details:\n";
            robotDonkey->display(cout);
            robotDonkey->performRobotTask();
            cout << endl;
        }
    }

    if (!hasRobotDonkeys) {
        cout << "No HybridRobotDonkeys found in the list.\n";
    }
}

int main() {
    ifstream inputFile("animals.txt");
    ofstream file1("File1.txt"), file2("File2.txt");

    if (!inputFile) {
        cerr << "Error: Unable to open input file.\n";
        return 1;
    }

    Animal* animals[MAX_ANIMALS];
    int count = 0;

    while (count < MAX_ANIMALS) {
        Animal* animal = nullptr;
        if (inputFile >> animal) {
            animals[count++] = animal;
        }
        else {
            break;
        }
    }


    cout << "All animals have been loaded successfully from the file.\n";

    for (int i = 0; i < count; ++i) {
        animals[i]->display(file1);
    }
    cout << "All animal details have been saved to File1.txt.\n";

    interactiveSearch(animals, count);

    demonstrateRobotFunctionality(animals, count);

    for (int i = 0; i < count; ++i) {
        delete animals[i];
    }
    cout << "Memory cleaned up. Program execution complete.\n";

    return 0;
}
