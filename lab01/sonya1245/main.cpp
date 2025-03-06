#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Group.h"

using namespace std;

int main() {
    Group group;
    ifstream inputFile("students.txt");

    if (inputFile.is_open()) {
        inputFile >> group;
        inputFile.close();
    }

    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Search by Name\n";
        cout << "3. Search by Group Name\n";
        cout << "4. Search by Record Number\n";
        cout << "5. Search by Address\n";
        cout << "6. Search by City\n";
        cout << "7. Search by Subject Name\n";
        cout << "8. Search by Semester\n";
        cout << "9. Print all students\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Student student;
            cin >> student;
            group.addStudent(student);
        }
        else if (choice == 2) {
            string name;
            cout << "Enter name: ";
            cin >> name;
            group.searchByName(name);
        }
        else if (choice == 3) {
            string groupName;
            cout << "Enter group name: ";
            cin >> groupName;
            group.searchByGroupName(groupName);
        }
        else if (choice == 4) {
            string recordNumber;
            cout << "Enter record number: ";
            cin >> recordNumber;
            group.searchByRecordNumber(recordNumber);
        }
        else if (choice == 5) {
            Address address;
            cin >> address;
            group.searchByAddress(address);
        }
        else if (choice == 6) {
            string city;
            cout << "Enter city: ";
            cin >> city;
            group.searchByCity(city);
        }
        else if (choice == 7) {
            string subjectName;
            cout << "Enter subject name: ";
            cin >> subjectName;
            group.searchBySubjectName(subjectName);
        }
        else if (choice == 8) {
            int semester;
            cout << "Enter semester: ";
            cin >> semester;
            group.searchBySemester(semester);
        }
        else if (choice == 9) {
            group.printStudents();
        }
        else if (choice == 10) {
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}