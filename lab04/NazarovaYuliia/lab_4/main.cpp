#include "StudentManager.h"

int main() {
    Student_Manager manager;
    int choice;
    string fName, lName, grp;
    do {
        cout << "\n1. Add student";
        cout << "\n2. Remove student";
        cout << "\n3. Search student by first name";
        cout << "\n4. Search student by last name";
        cout << "\n5. Search students by group";
        cout << "\n6. Display all students";
        cout << "\n0. Exit";
        cout << "\nChoose an option: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter first name, last name, group: ";
            cin >> fName >> lName >> grp;
            manager.addStudent(fName, lName, grp);
            break;
        case 2:
            cout << "Enter first name and last name of the student to remove: ";
            cin >> fName >> lName;
            manager.removeStudent(fName, lName);
            break;
        case 3:
            cout << "Enter first name: ";
            cin >> fName;
            manager.findStudentByName(fName);
            break;
        case 4:
            cout << "Enter last name: ";
            cin >> lName;
            manager.findStudentByLastName(lName);
            break;
        case 5:
            cout << "Enter group: ";
            cin >> grp;
            manager.findStudentsByGroup(grp);
            break;
        case 6:
            manager.displayAll();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Unknown command!" << endl;
        }
    } while (choice != 0);
    return 0;
}