#include <iostream>
#include <fstream>
#include "Group.h"
#include "Student.h"
#include "Address.h"
#include "RecordBook.h"
#include "Subject.h"

using namespace std;



bool checkGroupExists(Group* group) {
    if (group == nullptr) {
        cout << "Please create a group first (Option 1).\n";
        return false;
    }
    return true;
}

int main() {
    Group* group = nullptr;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter Group Name\n";
        cout << "2. Add Student\n";
        cout << "3. Search by Name\n";
        cout << "4. Search by Group Name\n";
        cout << "5. Search by Record Book Number\n";
        cout << "6. Search by Address\n";
        cout << "7. Print all students in group\n";
        cout << "8. Remove Student\n";
        cout << "9. Save to File\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string groupName;
            cout << "Enter the group name: ";
            cin >> groupName;

            if (group != nullptr) {
                delete group;
            }

            group = new Group(groupName, nullptr, 0);
            cout << "Group " << groupName << " has been created.\n";
        }
        else if (choice == 2) {
            if (!checkGroupExists(group)) continue;
            Student student;
            cin >> student;
            group->addStudent(student);
        }
        else if (choice == 3) {
            if (!checkGroupExists(group)) continue;
            string name;
            cout << "Enter name: ";
            cin >> name;
            group->searchByName(name);
        }
        else if (choice == 4) {
            if (!checkGroupExists(group)) continue;
            string groupName;
            cout << "Enter group name: ";
            cin >> groupName;
            group->searchByGroupName(groupName);
        }
        else if (choice == 5) {
            if (!checkGroupExists(group)) continue;
            string recordNumber;
            cout << "Enter record number: ";
            cin >> recordNumber;
            group->searchByRecordNumber(recordNumber);
        }
        else if (choice == 6) {
            if (!checkGroupExists(group)) continue;
            Address address;
            cin >> address;
            group->searchByAddress(address);
        }
        else if (choice == 7) {
            if (!checkGroupExists(group)) continue;
            group->printStudents();
        }
        else if (choice == 8) {
            if (!checkGroupExists(group)) continue;
            string name;
            cout << "Enter name to remove: ";
            cin >> name;
            group->removeStudent(name);
        }
        else if (choice == 9) {
            if (!checkGroupExists(group)) continue;

            ofstream outFile("students.txt");
            if (outFile.is_open()) {
                outFile << *group;
                outFile.close();
                cout << "Data saved to file.\n";
            }
            else {
                cout << "Error opening file for saving.\n";
            }
        }
        else if (choice == 10) {
            if (group != nullptr) {
                delete group;
            }
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
