#include <iostream>
#include <fstream>
#include "Student.h"
#include "PaperCheatSheet.h"
#include "ElectronicCheatSheet.h"

using namespace std;

void readStudentsFromFile(const string& data, Student**& students, int& studentCount);
void writeSortedCheatSheetsToFile(const string& data, Student** students, int studentCount);
void writeElectronicCheatSheetsToFile(const string& data, Student** students, int studentCount);
void sortCheatSheets(CheatSheet** cheatSheets, int count);

int main() {
    Student** students = nullptr;
    int studentCount = 0;

    readStudentsFromFile("students.txt", students, studentCount);

    writeSortedCheatSheetsToFile("sorted_cheatsheets.txt", students, studentCount);
    writeElectronicCheatSheetsToFile("electronic_cheatsheets.txt", students, studentCount);

    for (int i = 0; i < studentCount; ++i) {
        delete students[i];
    }
    delete[] students;

    cout << "Data has been processed and saved to 'sorted_cheatsheets.txt' and 'electronic_cheatsheets.txt'." << endl;

    return 0;
}

void readStudentsFromFile(const string& data, Student**& students, int& studentCount) {
    ifstream file(data);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << data << endl;
        return;
    }

    while (file >> ws && !file.eof()) {
        Student* student = new Student();
        file >> *student;
        Student** newStudents = new Student * [studentCount + 1];
        for (int i = 0; i < studentCount; ++i) {
            newStudents[i] = students[i];
        }
        newStudents[studentCount] = student;
        delete[] students;
        students = newStudents;
        studentCount++;
    }

    file.close();
}

void writeSortedCheatSheetsToFile(const string& data, Student** students, int studentCount) {
    int totalCheatSheets = 0;
    for (int i = 0; i < studentCount; ++i) {
        totalCheatSheets += students[i]->getCheatSheetCount();
    }

    CheatSheet** allCheatSheets = new CheatSheet * [totalCheatSheets];
    int index = 0;
    for (int i = 0; i < studentCount; ++i) {
        CheatSheet** studentCheatSheets = students[i]->getCheatSheets();
        int count = students[i]->getCheatSheetCount();
        for (int j = 0; j < count; ++j) {
            allCheatSheets[index++] = studentCheatSheets[j];
        }
    }

    sortCheatSheets(allCheatSheets, totalCheatSheets);

    ofstream file(data);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << data << endl;
        return;
    }

    file << "Sorted cheat sheets by subject and number:" << endl;
    for (int i = 0; i < totalCheatSheets; ++i) {
        file << *allCheatSheets[i] << endl;
    }

    file.close();
    delete[] allCheatSheets;
}

void writeElectronicCheatSheetsToFile(const string& data, Student** students, int studentCount) {
    ofstream file(data);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << data << endl;
        return;
    }

    file << "Electronic cheat sheets on 'comp':" << endl;
    int count = 0;
    for (int i = 0; i < studentCount; ++i) {
        CheatSheet** cheatSheets = students[i]->getCheatSheets();
        int cheatSheetCount = students[i]->getCheatSheetCount();
        for (int j = 0; j < cheatSheetCount; ++j) {
            ElectronicCheatSheet* electronicCheatSheet = dynamic_cast<ElectronicCheatSheet*>(cheatSheets[j]);
            if (electronicCheatSheet && electronicCheatSheet->getStorageName() == "comp") {
                file << *electronicCheatSheet << endl;
                count++;
            }
        }
    }
    file << "Total electronic cheat sheets on 'comp': " << count << endl;

    file.close();
}

void sortCheatSheets(CheatSheet** cheatSheets, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (*cheatSheets[j] < *cheatSheets[i]) {
                CheatSheet* temp = cheatSheets[i];
                cheatSheets[i] = cheatSheets[j];
                cheatSheets[j] = temp;
            }
        }
    }
}