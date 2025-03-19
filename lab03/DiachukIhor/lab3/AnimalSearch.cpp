#include "AnimalSearch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void sortAnimals(Animal* animals[], int animalCount) {
    for (int i = 0; i < animalCount - 1; ++i) {
        for (int j = 0; j < animalCount - i - 1; ++j) {
            if (animals[j]->getBirthYear() > animals[j + 1]->getBirthYear()) {
                Animal* temp = animals[j];
                animals[j] = animals[j + 1];
                animals[j + 1] = temp;
            }
        }
    }
}

void searchByName(Animal* animals[], int animalCount, const string& name, ofstream& outFile) {
    int foundCount = 0;
    for (int i = 0; i < animalCount; ++i) {
        if (animals[i]->getName() == name) {
            animals[i]->print(outFile);
            foundCount++;
        }
    }
    if (foundCount == 0) {
        cout << "Не знайдено тварину з таким ім'ям." << endl;
    }
}

void searchByBirthYear(Animal* animals[], int animalCount, int year, ofstream& outFile) {
    int foundCount = 0;
    for (int i = 0; i < animalCount; ++i) {
        if (animals[i]->getBirthYear() == year) {
            animals[i]->print(outFile);
            foundCount++;
        }
    }
    if (foundCount == 0) {
        cout << "Не знайдено тварину з таким роком народження." << endl;
    }
}

void searchByColor(Animal* animals[], int animalCount, const string& color, ofstream& outFile) {
    int foundCount = 0;
    for (int i = 0; i < animalCount; ++i) {
        Horse* horse = dynamic_cast<Horse*>(animals[i]);
        if (horse && horse->getColor() == color) {
            horse->print(outFile);
            foundCount++;
        }
    }
    if (foundCount == 0) {
        cout << "Не знайдено коня з таким кольором." << endl;
    }
}

void searchByHeight(Animal* animals[], int animalCount, double height, ofstream& outFile) {
    int foundCount = 0;
    for (int i = 0; i < animalCount; ++i) {
        Donkey* donkey = dynamic_cast<Donkey*>(animals[i]);
        if (donkey && donkey->getHeight() <= height) {
            donkey->print(outFile);
            foundCount++;
        }
    }
    if (foundCount == 0) {
        cout << "Не знайдено осла з такою висотою." << endl;
    }
}