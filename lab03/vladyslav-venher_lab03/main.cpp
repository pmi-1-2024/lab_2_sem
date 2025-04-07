#include "Horse.h"
#include "Donkey.h"
#include "HybridAnimal.h"
#include "Functions.h"
#include <fstream>
#include <iostream>

const int MAX_ANIMALS = 100;

int main() {
	ifstream inputFile("animals.txt");
	if (!inputFile) {
		cerr << "Error opening input file.\n";
		return 1;
	}

	Animal* animals[MAX_ANIMALS] = { nullptr };
	int count = 0;

	while (count < MAX_ANIMALS) {
		int type;
		if (!(inputFile >> type)) break;

		Animal* animal = nullptr;
		if (type == 1) {
			animal = new Horse();
		}
		else if (type == 2) {
			animal = new Donkey();
		}
		else if (type == 3) {
			animal = new HybridAnimal();
		}

		if (animal) {
			if (inputFile >> *animal) {
				animals[count++] = animal;
			}
			else {
				delete animal;
				break;
			}
		}
		else {
			cerr << "Failed to create animal.\n";
			break;
		}
	}

	int choice;

	ofstream clearFile("output.txt");
	clearFile.close();

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
			string name;
			cout << "Enter name: ";
			cin >> name;
			searchByName(animals, count, name);
		}
		else if (choice == 2) {
			int year;
			cout << "Enter birth year: ";
			cin >> year;
			searchByYear(animals, count, year);
		}
		else if (choice == 3) {
			searchWhiteHorses(animals, count);
		}
		else if (choice == 4) {
			searchShortDonkeys(animals, count);
		}
	} while (choice != 5);

	for (int i = 0; i < count; ++i) {
		delete animals[i];
	}

	inputFile.close();
	return 0;
}