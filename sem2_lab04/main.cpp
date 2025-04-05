#include <iostream>
#include "student_manager.h"

using namespace std;

void printMenu() {
    cout << "\nStudent Manager Menu:" << endl;
    cout << "1. Display all students" << endl;
    cout << "2. Add a student" << endl;
    cout << "3. Remove a student" << endl;
    cout << "4. Find a student" << endl;
    cout << "5. Update student data" << endl;
    cout << "6. Save to file" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    Student_Manager manager;
    manager.loadFromFile("students.txt");  

    int choice;

    while (true) {
        printMenu();
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\nAll Students:" << endl;
            manager.printAllStudents();
            break;
        }
        case 2: {
            string firstName, lastName, groupName;
            cout << "\nEnter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter group name: ";
            cin >> groupName;

            Student newStudent(firstName, lastName, groupName);
            manager.addStudent(newStudent);
            break;
        }
        case 3: {
            string firstName, lastName;
            cout << "\nEnter the first name of the student to remove: ";
            cin >> firstName;
            cout << "Enter the last name of the student to remove: ";
            cin >> lastName;
            manager.removeStudent(firstName, lastName);
            break;
        }
        case 4: {
            string firstName, lastName;
            cout << "\nEnter the first name of the student to find: ";
            cin >> firstName;
            cout << "Enter the last name of the student to find: ";
            cin >> lastName;
            manager.findStudent(firstName, lastName);
            break;
        }
        case 5: {
            string firstName, lastName;
            cout << "\nEnter the first name of the student to update: ";
            cin >> firstName;
            cout << "Enter the last name of the student to update: ";
            cin >> lastName;

            string newFirstName, newLastName, newGroupName;
            cout << "Enter new first name: ";
            cin >> newFirstName;
            cout << "Enter new last name: ";
            cin >> newLastName;
            cout << "Enter new group name: ";
            cin >> newGroupName;

            Student updatedStudent(newFirstName, newLastName, newGroupName);
            manager.replaceStudent(firstName, lastName, updatedStudent);
            break;
        }
        case 6: {
            manager.saveToFile("updated_students.txt");
            cout << "\nData saved to file." << endl;
            break;
        }
        case 7: {
            cout << "Exiting the program." << endl;
            return 0;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
