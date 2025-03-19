#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Animal.h"
#include "Horse.h"
#include "Donkey.h"
#include "Mule.h"
#include "AnimalSearch.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    cout << "����������� ������ 3" << endl;
    cout << "������ 4" << endl;
    cout << "������� ������� ����� �̲11 ����� ����" << endl << endl;
    cout << "���������� �� ����:" << endl;
    cout << "��� ����� ����� ��� � ����� input.txt." << endl;
    cout << "������� ��� txt-����� ���� � ������ ������ ���." << endl << endl;

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

    sortAnimals(animals, animalCount);

    for (int i = 0; i < animalCount; ++i) {
        animals[i]->print(outFile1);
    }

    bool continueSearching = true;

    cout << "������ ��������� ������:" << endl;
    cout << "1. ����� �� ��'��" << endl;
    cout << "2. ����� �� ����� ����������" << endl;
    cout << "3. ����� �� �������� (����� ��� �����)" << endl;
    cout << "4. ����� �� ������� (����� ��� ����)" << endl;
    cout << "0. �����" << endl;

    while (continueSearching) {
        cout << "��� ����: ";
        int choice;
        cin >> choice;

        string name;
        int year;
        string color;
        double height;

        switch (choice) {
        case 1:
            cout << "������ ��'� �������: ";
            cin >> name;
            searchByName(animals, animalCount, name, outFile2);
            break;
        case 2:
            cout << "������ �� ����������: ";
            cin >> year;
            searchByBirthYear(animals, animalCount, year, outFile2);
            break;
        case 3:
            cout << "������ ����: ";
            cin >> color;
            searchByColor(animals, animalCount, color, outFile2);
            break;
        case 4:
            cout << "������ ����������� ������: ";
            cin >> height;
            searchByHeight(animals, animalCount, height, outFile2);
            break;
        case 0:
            cout << "����� � ��������.\n";
            continueSearching = false;
            break;
        default:
            cout << "������� ����! ��������� �� ���.\n";
        }
    }

    cout << "����� ���������!" << endl;

    for (int i = 0; i < animalCount; ++i) {
        delete animals[i];
    }

    inFile.close();
    outFile1.close();
    outFile2.close();

    return 0;
}