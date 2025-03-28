#include <iostream>
#include <fstream>
#include "Group.h"

using namespace std;

Group* groups = nullptr;
int groupCount = 0;

void loadGroups() {
    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "Error: File not found!" << endl;
        return;
    }

    file >> groupCount;
    groups = new Group[groupCount];

    for (int i = 0; i < groupCount; i++) {
        file >> groups[i];
    }

    file.close();
}

void searchByGroupName() {
    string name;
    cout << "Enter group name: ";
    cin >> name;

    for (int i = 0; i < groupCount; i++) {
        if (groups[i].getGroupName() == name) {
            cout << groups[i] << endl;
            return;
        }
    }
    cout << "Group not found." << endl;
}

void searchByStudentName() {
    string studentName;
    cout << "Enter student name: ";
    cin >> studentName;

    for (int i = 0; i < groupCount; i++) {
        for (int j = 0; j < groups[i].getStudentCount(); j++) {
            if (groups[i][j].getName() == studentName) {
                cout << "Found in group: " << groups[i].getGroupName() << endl;
                cout << groups[i][j] << endl;
                return;
            }
        }
    }
    cout << "Student not found." << endl;
}

void searchByCity() {
    string city;
    cout << "Enter city: ";
    cin >> city;

    bool found = false;
    for (int i = 0; i < groupCount; i++) {
        for (int j = 0; j < groups[i].getStudentCount(); j++) {
            if (groups[i][j].getAddress().getCity() == city) {
                cout << groups[i][j] << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "No students found in this city." << endl;
    }
}

void menu() {
    int choice;
    do {
        cout << "1. Show all groups"<<endl;
        cout << "2. Search by group name"<<endl;
        cout << "3. Search by student name"<<endl;
        cout << "4. Search by city"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < groupCount; i++) {
                cout << groups[i] << endl;
            }
            break;
        case 2:
            searchByGroupName();
            break;
        case 3:
            searchByStudentName();
            break;
        case 4:
            searchByCity();
            break;
        case 5:
            cout << "Exiting..."<<endl;
            break;
        default:
            cout << "Invalid choice. Try again."<<endl;
        }
    } while (choice != 5);
}

int main() {
    loadGroups();

    if (groupCount == 0) {
        cout << "No groups loaded." << endl;
    }
    else {
        menu();
    }

    delete[] groups;
    return 0;
}
