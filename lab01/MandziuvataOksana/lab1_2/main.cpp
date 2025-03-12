#include <iostream>
#include <string>
#include "Group.h"
#include "Student.h"
#include "Address.h"
#include "RecordBook.h"
#include "Subject.h"

using namespace std;

int main() {
    // Створення групи
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
            Student student;
            cin >> student; // Введення студента

            group->addStudent(student); // Додавання студента в групу
            cout << "Student has been added.\n";
        }
        else if (choice == 3) {
            string name;
            cout << "Enter student name: ";
            cin >> name;
            group->searchByName(name); // Пошук студента за іменем
        }
        else if (choice == 4) {
            string groupName;
            cout << "Enter group name: ";
            cin >> groupName;
            group->searchByGroupName(groupName); // Пошук по групі
        }
        else if (choice == 5) {
            string recordNumber;
            cout << "Enter record book number: ";
            cin >> recordNumber;
            group->searchByRecordNumber(recordNumber); // Пошук за номером заліковки
        }
        else if (choice == 6) {
            Address address;
            cin >> address; // Введення адреси
            group->searchByAddress(address); // Пошук за адресою
        }
        else if (choice == 7) {
            group->printStudents(); // Виведення всіх студентів групи
        }
        else if (choice == 8) {
            string name;
            cout << "Enter student name to remove: ";
            cin >> name;
            group->removeStudent(name); // Видалення студента з групи
        }
        else if (choice == 9) {
            // Збереження групи в файл (якщо потрібно)
            cout << "Saving to file is not implemented yet.\n";
        }
        else if (choice == 10) {
            // Завершення програми
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
