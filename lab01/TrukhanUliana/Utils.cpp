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
    cout << "1. Enter group name" << endl;
    cout << "2. Add student" << endl;
    cout << "3. Remove student" << endl;
    cout << "4. Display group" << endl;
    cout << "5. Search by address" << endl;
    cout << "6. Search by record number" << endl;
    cout << "7. Search by subject name" << endl;
    cout << "Enter your choice: ";
}

void readFromFile(ifstream& file, int& studentCount, Student*& students) {
    if (!file.is_open()) {
        cout << "Eror: file didn`t open!" << endl;
        return;
    }

    file >> studentCount;

    // Звільняємо пам'ять перед новим виділенням, якщо потрібно
    if (students != nullptr) {
        delete[] students;
    }

    students = new Student[studentCount];  // Виділяємо пам’ять

    for (int i = 0; i < studentCount; i++) {
        file >> students[i];
    }
}
