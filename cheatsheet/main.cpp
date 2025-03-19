#include <iostream>
#include <fstream>
#include <sstream> // мала підключити цю бібліотеку бо не зчитувався файл
#include "Student.h"
#include "PaperCheatSheet.h"
#include "ElectronicCheatSheet.h"
using namespace std;

void readStudentsFromFile(const string& filename, Student* students, int& count) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    count = 0;
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        string name, group;
        istringstream iss(line);
        getline(iss, name, ' ');
        getline(iss, group);

        students[count] = Student(name, group);

        while (getline(file, line)) {
            if (line.empty()) break;

            istringstream iss(line);
            int type;
            iss >> type;

            if (type == 1) {
                string subject, size, hidingPlace;
                int number;
                iss >> subject >> number >> size >> hidingPlace;
                students[count].addCheatSheet(new PaperCheatSheet(subject, number, size, hidingPlace));
            }
            else if (type == 2) {
                string subject, mediaName;
                int number;
                iss >> subject >> number >> mediaName;
                students[count].addCheatSheet(new ElectronicCheatSheet(subject, number, mediaName));
            }
        }

        count++;
    }

    cout << "Total students read: " << count;
}

void writeSortedCheatSheets(const string& filename, Student* students, int count) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename;
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
            cheatSheets[j]->print(file);
            file << "\n";
        }
    }
    cout << "Sorted cheat sheets written to: " << filename;
}

void writeElectronicCheatSheets(const string& filename, Student* students, int count) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    int compCount = 0;
    for (int i = 0; i < count; ++i) {
        CheatSheet** cheatSheets = students[i].getCheatSheets();
        int cheatSheetCount = students[i].getCheatSheetCount();

        for (int j = 0; j < cheatSheetCount; ++j) {
            if (cheatSheets[j]->isElectronic()) {
                ElectronicCheatSheet* ecs = static_cast<ElectronicCheatSheet*>(cheatSheets[j]);
                if (ecs->getMediaName() == "comp") {
                    ecs->print(file);
                    file << "\n";
                    compCount++;
                }
            }
        }
    }

    file << "Total electronic cheat sheets on 'comp': " << compCount;
    cout << "Electronic cheat sheets written to: " << filename;
}
int main() {
    Student students[2];
    int studentCount = 0;

    readStudentsFromFile("data.txt", students, studentCount);
    writeSortedCheatSheets("sorted_cheatsheets.txt", students, studentCount);
    writeElectronicCheatSheets("electronic_comp.txt", students, studentCount);
    cout << "Data has been processed. Check the files.";
    return 0;
}