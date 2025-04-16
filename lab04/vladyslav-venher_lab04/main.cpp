#include <iostream>
#include "Student-Manager.h"
using namespace std;

void menu() {
    cout << "MENU\n";
    cout << "1. Add student.\n";
    cout << "2. Remove student.\n";
    cout << "3. Find student.\n";
    cout << "4. Display students.\n";
    cout << "5. Update student.\n";
    cout << "0. Exit.\n";
}

int main() {
    StudentManager manager;
    int choice;
    string firstName, lastName;
    do {
        menu();
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Student st;
            cin >> st;
            manager.addNewStudent(st);
            break;
        }
        case 2:
            cout << "Enter first and last name of student to remove: ";
            cin >> firstName >> lastName;
            manager.deleteStudent(firstName, lastName);
            break;
        case 3:
            cout << "Enter first and last name of student to search: ";
            cin >> firstName >> lastName;
            if (Student_Node* found = manager.findStudent(firstName, lastName)) {
                cout << found->info << endl;
            }
            else {
                cout << "Student not found.\n";
            }
            break;
        case 4:
            cout << "Student list:\n";
            manager.displayStudents();
            break;
        case 5:
            cout << "Enter first and last name of student to update: ";
            cin >> firstName >> lastName;
            manager.updateStudent(firstName, lastName);
            break;
        }
    } while (choice != 0);
    return 0;
}
