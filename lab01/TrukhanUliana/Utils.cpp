#include "Utils.h"

void menu1() {
    cout << "Menu:" << endl;
    cout << "1. By name" << endl;
    cout << "2. By city (address)" << endl;
    cout << "3. By group" << endl;
    cout << "4. By record book number" << endl;
    cout << "5. By subject name" << endl;
    cout << "6. By semester" << endl;
    cout << "7. Group menu" << endl;
    cout << "Enter your choice: ";
}

void menu2() {
    cout << "Group menu:" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Remove student" << endl;
    cout << "3. Display group" << endl;
    cout << "4. Search by address" << endl;
    cout << "5. Search by record number" << endl;
    cout << "6. Search by subject name" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

void readFromFile(ifstream& file, int& studentCount, Student*& students) {
    if (!file.is_open()) {
        cout << "Eror: file didn`t open!" << endl;
        return;
    }

    file >> studentCount;

    if (students != nullptr) {
        delete[] students;
    }

    students = new Student[studentCount];

    for (int i = 0; i < studentCount; i++) {
        file >> students[i];
    }
}

