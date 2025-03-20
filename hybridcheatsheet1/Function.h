#ifndef FUNCTION_H
#define FUNCTION_H

#include "PaperCheatSheet.h"
#include "ElectronicCheatSheet.h"
#include "HybridCheatSheet.h"
#include "Student.h"
#include <iostream>
#include <fstream>
using namespace std;

void readStudentsFromFile(const string& filename, Student* students, int& count);
void writeSortedCheatSheets(const string& filename, Student* students, int count);
void writeElectronicCheatSheets(const string& filename, Student* students, int count);
void searchCheatSheetsByCriteria(Student* students, int count);
void writeCheatSheetsByTypeToFile(const string& filename, Student* students, int count, const string& type);

void readStudentsFromFile(const string& filename, Student* students, int& count) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    count = 0;
    while (file >> students[count]) {
        count++;
    }

    cout << "Total students read: " << count << endl;
    file.close();
}

void writeSortedCheatSheets(const string& filename, Student* students, int count) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        CheatSheet** cheatSheets = students[i].getCheatSheets();
        int cheatSheetCount = students[i].getCheatSheetCount();
        for (int j = 0; j < cheatSheetCount - 1; ++j) {
            for (int k = j + 1; k < cheatSheetCount; ++k) {
                if (*cheatSheets[k] < *cheatSheets[j]) {
                    CheatSheet* temp = cheatSheets[j];
                    cheatSheets[j] = cheatSheets[k];
                    cheatSheets[k] = temp;
                }
            }
        }

        for (int j = 0; j < cheatSheetCount; ++j) {
            file << *cheatSheets[j] << "\n";
        }
    }

    cout << "Sorted cheat sheets written to: " << filename << endl;
    file.close();
}

void writeElectronicCheatSheets(const string& filename, Student* students, int count) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        students[i].writeElectronicOnComp(file);
    }

    cout << "Electronic cheat sheets written to: " << filename << endl;
    file.close();
}

void searchCheatSheetsByCriteria(Student* students, int count) {
    int choice;
    cout << "\nSearch:\n";
    cout << "1. By type (Paper, Electronic, Hybrid)\n";
    cout << "2. By subject\n";
    cout << "Enter choice: ";
    cin >> choice;

    string input;
    bool found = false;

    switch (choice) {
    case 1:
        int type;
        cout << "Enter type:\n1. Paper\n2. Electronic\n3. Hybrid\nChoice: ";
        cin >> type; 
        for (int i = 0; i < count; ++i) {
            CheatSheet** cheatSheets = students[i].getCheatSheets();
            int cheatSheetCount = students[i].getCheatSheetCount();

            for (int j = 0; j < cheatSheetCount; ++j) {
                bool match = (type == 1 && !cheatSheets[j]->isElectronic()) ||   
                    (type == 2 && cheatSheets[j]->isElectronic()) ||  
                    (type == 3 && cheatSheets[j]->isElectronic());    // hybrid = electronic too  

                if (match) {
                    cout << *cheatSheets[j] << endl;
                    found = true;
                }
            }
        }
        break;
    case 2:
        cout << "Enter subject: ";
        cin >> input;
        for (int i = 0; i < count; ++i) {
            CheatSheet** cheatSheets = students[i].getCheatSheets();
            int cheatSheetCount = students[i].getCheatSheetCount();

            for (int j = 0; j < cheatSheetCount; ++j) {
                if (cheatSheets[j]->getSubject() == input) {
                    cout << *cheatSheets[j] << endl;
                    found = true;
                }
            }
        }
        break;

    default:
        cout << "Invalid choice.\n";
    }

    if (!found) {
        cout << "No results found.\n";
    }
}

void writeCheatSheetsByTypeToFile(const string& filename, Student* students, int count, const string& type) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        CheatSheet** cheatSheets = students[i].getCheatSheets();
        int cheatSheetCount = students[i].getCheatSheetCount();

        for (int j = 0; j < cheatSheetCount; ++j) {
            bool match = (type == "Paper" && !cheatSheets[j]->isElectronic()) ||
                (type == "Electronic" && cheatSheets[j]->isElectronic()) ||
                (type == "Hybrid" && cheatSheets[j]->isElectronic());

            if (match) {
                file << *cheatSheets[j] << "\n";
            }
        }
    }

    cout << type << " cheat sheets written to: " << filename << endl;
    file.close();
}

#endif
