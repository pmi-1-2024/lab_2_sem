#include <iostream>
#include "Student.h"
#include "Utils.h"

using namespace std;

void menu(Student* students, int count) {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Show all students\n";
        cout << "2. Search student\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < count; ++i) {
                cout << students[i] << endl;
            }
            break;
        case 2:
            searchStudents(students, count);
            break;
        case 3:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);
}

int main() {
    Student* students = nullptr;
    int studentCount = 0;

    loadStudents("students.txt", students, studentCount);
    menu(students, studentCount);
    

    delete[] students;
    return 0;
}
