#include "Student_Manager.h"
#include <iostream>

void Student_Manager::addStudent() {
    Student student;
    cin.ignore();
    cin >> student;

    Student_Link* newNode = new Student_Link(student);
    newNode->next = students.getHead();
    students.setHead(newNode);

    cout << "Student added successfully.\n";
}

void Student_Manager::removeStudent() {
    cout << "Enter student name to remove: ";
    string name;
    cin.ignore();
    getline(cin, name);

    Student_Link* current = (Student_Link*)students.getHead();
    Student_Link* prev = nullptr;

    while (current) {
        if (current->student.getName() == name) {
            if (prev) prev->next = current->next;
            else students.setHead(current->next);
            delete current;
            cout << "Student removed successfully.\n";
            return;
        }
        prev = current;
        current = (Student_Link*)current->next;
    }

    cout << "Student not found.\n";
}

void Student_Manager::findStudent() {
    int option;
    cout << "\nSearch by:\n";
    cout << "1. Name\n";
    cout << "2. Group\n";
    cout << "3. Record Number\n";
    cout << "Enter choice: ";
    cin >> option;
    cin.ignore();

    string searchValue;
    cout << "Enter search value: ";
    getline(cin, searchValue);

    Student_Link* current = (Student_Link*)students.getHead();
    bool found = false;

    while (current) {
        if ((option == 1 && current->student.getName() == searchValue) ||
            (option == 2 && current->student.getGroup() == searchValue) ||
            (option == 3 && current->student.getRecordNumber() == searchValue)) {
            cout << "Student found:\n" << current->student << "\n";
            found = true;
        }
        current = (Student_Link*)current->next;
    }

    if (!found) {
        cout << "No matching student found.\n";
    }
}

void Student_Manager::updateStudent() {
    cout << "Enter student name to update: ";
    string name;
    cin.ignore();
    getline(cin, name);

    Student_Link* current = (Student_Link*)students.getHead();
    while (current) {
        if (current->student.getName() == name) {
            cout << "Enter new data:\n";
            cin >> current->student;
            cout << "Student data updated successfully.\n";
            return;
        }
        current = (Student_Link*)current->next;
    }

    cout << "Student not found.\n";
}

void Student_Manager::displayAllStudents() {
    Student_Link* current = (Student_Link*)students.getHead();
    if (!current) {
        cout << "No students in the list.\n";
        return;
    }
    while (current) {
        cout << current->student << "\n";
        current = (Student_Link*)current->next;
    }
}

void Student_Manager::menu() {
    int choice;
    do {
        cout << "\n1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Find Student\n";
        cout << "4. Update Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: removeStudent(); break;
        case 3: findStudent(); break;
        case 4: updateStudent(); break;
        case 5: displayAllStudents(); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}
