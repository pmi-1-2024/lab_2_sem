#include <iostream>
#include <fstream>
#include "Group.h"
#include "Student.h"
#include "Address.h"
#include "RecordBook.h"
#include "Subject.h"

using namespace std;

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
