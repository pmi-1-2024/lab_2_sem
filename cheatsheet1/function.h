#ifndef FUNCTION_H
#define FUNCTION_H
#include "PaperCheatSheet.h"
#include "ElectronicCheatSheet.h"
#include "Student.h"
#include <iostream>
#include <fstream>

using namespace std;

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
                    swap(cheatSheets[j], cheatSheets[k]);
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


#endif

