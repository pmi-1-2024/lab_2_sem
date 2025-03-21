#include "Student_Manager.h"

void displayMenu() {
    cout << "\n Menu\n";
    cout << "1. Add Student\n";
    cout << "2. Remove Student\n";
    cout << "3. Find Student by Name\n";
    cout << "4. Find Student by Group\n";
    cout << "5. Find Student by Address\n";
    cout << "6. Update Student\n";
    cout << "7. Print All Students\n";
    cout << "8. Exit\n";
    cout << "Choose an option: ";
}

Student inputStudentData() {
    string name, major, address, group;
    int age;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter major: ";
    getline(cin, major);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter group: ";
    getline(cin, group);

    return Student(name, age, major, address, group);
}

int main() {
    Student_Manager manager;
    int choice;
    string name, group, address;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1: {
            Student s = inputStudentData();
            manager.addStudent(s);
            break;
        }
        case 2: {
            cout << "Enter name of the student to remove: ";
            getline(cin, name);
            manager.removeStudent(name);
            break;
        }
        case 3: {
            cout << "Enter name of the student to find: ";
            getline(cin, name);
            manager.findStudentByName(name);
            break;
        }
        case 4: {
            cout << "Enter group to find students: ";
            getline(cin, group);
            manager.findStudentByGroup(group);
            break;
        }
        case 5: {
            cout << "Enter address to find students: ";
            getline(cin, address);
            manager.findStudentByAddress(address);
            break;
        }
        case 6: {
            cout << "Enter name of the student to update: ";
            getline(cin, name);
            Student newData = inputStudentData();
            manager.updateStudent(name, newData);
            break;
        }
        case 7: {
            manager.printAllStudents();
            break;
        }
        case 8: {
            cout << "Exiting the program" << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 8);

    return 0;
}