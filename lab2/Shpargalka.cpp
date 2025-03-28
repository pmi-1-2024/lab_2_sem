#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct CheatSheet {
    string subject;
    int number = 0; // Ініціалізація за замовчуванням
};

struct PaperCheatSheet : CheatSheet {
    string size;
    string hidingPlace;
};

struct ElectronicCheatSheet : CheatSheet {
    string deviceName;
};

struct Student {
    string name;
    string group;
    CheatSheet* cheatSheets = nullptr; // Ініціалізація за замовчуванням
    int cheatSheetCount = 0; // Ініціалізація за замовчуванням
};

bool compareCheatSheets(const CheatSheet& a, const CheatSheet& b) {
    if (a.subject == b.subject) {
        return a.number < b.number;
    }
    return a.subject < b.subject;
}

int main() {
    const int MAX_STUDENTS = 2;
    Student* students = new Student[MAX_STUDENTS];
    int electronicCount = 0;
    CheatSheet* electronicCheatSheets = nullptr;

    ifstream inputFile("input.txt");
    ofstream allCheatSheetsFile("all_cheat_sheets.txt");
    ofstream electronicCheatsFile("electronic_cheat_sheets.txt");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        inputFile >> students[i].name >> students[i].group;
        inputFile >> students[i].cheatSheetCount;

        students[i].cheatSheets = new CheatSheet[students[i].cheatSheetCount];
        for (int j = 0; j < students[i].cheatSheetCount; j++) {
            string type;
            inputFile >> type;

            if (type == "paper") {
                PaperCheatSheet paper;
                inputFile >> paper.subject >> paper.number >> paper.size >> paper.hidingPlace;
                students[i].cheatSheets[j] = paper;
            }
            else if (type == "electronic") {
                ElectronicCheatSheet electronic;
                inputFile >> electronic.subject >> electronic.number >> electronic.deviceName;
                students[i].cheatSheets[j] = electronic;

                if (electronic.deviceName == "комп") {
                    CheatSheet* temp = new CheatSheet[electronicCount + 1];
                    for (int k = 0; k < electronicCount; k++) {
                        temp[k] = electronicCheatSheets[k];
                    }
                    temp[electronicCount++] = electronic;
                    delete[] electronicCheatSheets;
                    electronicCheatSheets = temp;
                }
            }
        }
    }

    // Сортування всіх шпаргалок
    for (int i = 0; i < MAX_STUDENTS; i++) {
        sort(students[i].cheatSheets, students[i].cheatSheets + students[i].cheatSheetCount, compareCheatSheets);

        for (int j = 0; j < students[i].cheatSheetCount; j++) {
            allCheatSheetsFile << students[i].cheatSheets[j].subject << " " << students[i].cheatSheets[j].number << endl;
        }
    }

    // Виведення електронних шпаргалок
    for (int i = 0; i < electronicCount; i++) {
        electronicCheatsFile << electronicCheatSheets[i].subject << " " << electronicCheatSheets[i].number << endl;
    }
    electronicCheatsFile << "Кількість електронних шпаргалок на носії «комп»: " << electronicCount << endl;

    // Очищення пам'яті
    for (int i = 0; i < MAX_STUDENTS; i++) {
        delete[] students[i].cheatSheets;
    }
    delete[] students;
    delete[] electronicCheatSheets;

    inputFile.close();
    allCheatSheetsFile.close();
    electronicCheatsFile.close();

    return 0;
}
