#include <iostream>
#include <fstream>
#include "Group.h"

using namespace std;

void printMenu() {
    cout << "\nMenu:\n";
    cout << "1. Show all groups\n";
    cout << "2. Search student by surname\n";
    cout << "3. Search students by group name\n";
    cout << "4. Search student by record book number\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    ifstream inputFile("information.txt");
    if (!inputFile) {
        cerr << "Error: Cannot open file!" << endl;
        return 1;
    }

    int groupCount;
    inputFile >> groupCount;
    Group* groups = new Group[groupCount];

    // Reading groups and students from file
    for (int i = 0; i < groupCount; ++i) {
        inputFile >> groups[i];
    }
    inputFile.close();

    int choice;
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1: {  // Show all groups
            for (int i = 0; i < groupCount; ++i) {
                cout << groups[i] << endl;
            }
            break;
        }

        case 2: {  // Search student by surname
            string surname;
            cout << "Enter student's surname: ";
            cin >> surname;
            bool found = false;

            for (int i = 0; i < groupCount; ++i) {
                try {
                    Student foundStudent = groups[i][surname];
                    cout << "Student found:\n" << foundStudent << endl;
                    found = true;
                    break;
                }
                catch (const invalid_argument&) {}
            }

            if (!found) {
                cout << "No student with this surname found.\n";
            }
            break;
        }

        case 3: {  // Search students by group name
            string groupName;
            cout << "Enter group name: ";
            cin >> groupName;
            bool found = false;

            for (int i = 0; i < groupCount; ++i) {
                if (groups[i].getName() == groupName) {
                    cout << "Group " << groupName << ":\n" << groups[i] << endl;
                    found = true;
                }
            }

            if (!found) {
                cout << "Group not found.\n";
            }
            break;
        }

        case 4: {  // Search student by record book number
            int recordBookNumber;
            cout << "Enter record book number: ";
            cin >> recordBookNumber;
            bool found = false;

            for (int i = 0; i < groupCount; ++i) {
                for (int j = 0; j < groups[i].getStudentCount(); ++j) {
                    if (groups[i][j].getRecordBookNumber() == recordBookNumber) {
                        cout << "Student found:\n" << groups[i][j] << endl;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }

            if (!found) {
                cout << "No student with this record book number found.\n";
            }
            break;
        }

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    delete[] groups;
    return 0;
}






