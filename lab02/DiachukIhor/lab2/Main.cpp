#include <iostream>
#include <fstream>
#include <algorithm>
#include "Horse.h"
#include "Donkey.h"
#include "Mule.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    cout << "Лабораторна робота 2" << endl;
    cout << "Варіант 4" << endl;
    cout << "Виконав студент групи ПМІ11 Дячук Ігор" << endl << endl;
    cout << "інформація по коду:" << endl;
    cout << "Код сортує вхідні дані з файлу input.txt." << endl;
    cout << "Створює два txt-файли куди і записує вихідні дані." << endl << endl;

    ifstream inFile("input.txt");
    ofstream outFile1("output_sorted.txt");
    ofstream outFile2("output_filtered.txt");

    const int MAX_ANIMALS = 100;
    Animal* animals[MAX_ANIMALS];
    int animalCount = 0;

    string type;
    while (inFile >> type && animalCount < MAX_ANIMALS) {
        if (type == "Horse") {
            string name, color, breed;
            int year;
            inFile >> name >> year >> color >> breed;
            animals[animalCount++] = new Horse(name, year, color, breed);
        }
        else if (type == "Donkey") {
            string name, species;
            int year;
            double height;
            inFile >> name >> year >> species >> height;
            animals[animalCount++] = new Donkey(name, year, species, height);
        }
        else if (type == "Mule") {
            string name, nickname;
            int year;
            inFile >> name >> year >> nickname;
            animals[animalCount++] = new Mule(name, year, nickname);
        }
    }

    sort(animals, animals + animalCount, [](Animal* a, Animal* b) {
        return a->getBirthYear() < b->getBirthYear();
        });

    for (int i = 0; i < animalCount; ++i) {
        animals[i]->print(outFile1);
    }

    int count = 0;
    for (int i = 0; i < animalCount; ++i) {
        Horse* horse = dynamic_cast<Horse*>(animals[i]);
        Donkey* donkey = dynamic_cast<Donkey*>(animals[i]);
        if (horse && horse->getColor() == "white") {
            horse->print(outFile2);
            count++;
        }
        else if (donkey && donkey->getHeight() <= 1.5) {
            donkey->print(outFile2);
            count++;
        }
    }

    for (int i = 0; i < animalCount; ++i) {
        delete animals[i];
    }

    inFile.close();
    outFile1.close();
    outFile2.close();

    cout << "Дані посортовано!\n";
    return 0;
}