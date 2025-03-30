#include "Function.h"

int main() {
    Student students[2];
    int studentCount = 0;

    readStudentsFromFile("data.txt", students, studentCount);

    int choice;
    do {
        cout << "\nMain menu\n"
            << "1. Write sorted cheat sheets to file\n"
            << "2. Write only electronic cheat sheets to file\n"
            << "3. Search for cheat sheets\n"
            << "4. Write cheat sheets by type to file\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            writeSortedCheatSheets("sorted_cheatsheets.txt", students, studentCount);
            break;
        case 2:
            writeElectronicCheatSheets("electronic_comp.txt", students, studentCount);
            break;
        case 3:
            searchCheatSheetsByCriteria(students, studentCount);
            break;
        case 4: {
            string type;
            cout << "Enter type (Paper/Electronic/Hybrid): ";
            cin >> type;
            writeCheatSheetsByTypeToFile(type + "_cheatsheets.txt", students, studentCount, type);
            break;
        }
        case 0:
            cout << "Exiting..\n";
            break;
        default:
            cout << "Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
