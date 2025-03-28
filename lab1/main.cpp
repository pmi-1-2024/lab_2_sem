#include <iostream>
#include <string>
#include "Group.h"
#include "Student.h"
#include "Address.h"
#include "RecordBook.h"
#include "Subject.h"
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    

    while (1) {
        cout << "\nMenu:\n";
        cout << "1. Введіть назву групи\n";
        cout << "2. Додати студента\n";
        cout << "3. Пошук за іменем\n";
        cout << "4. Пошук за групою\n";
        cout << "5. Пошук за номером залікової книжки\n";
        cout << "6. Пошук за адресою\n";
        cout << "7. Видалити студента\n";
        cout << "0. Вихід\n";
        cout << "Введіть варіант: ";
        int choice;
        cin >> choice;
        Group* group = nullptr;

        if (choice == 1) {
            string groupName;
            cout << "Введіть назву групи: ";
            cin >> groupName;

            if (group != nullptr) {
                delete group;
            }
            group = new Group(groupName, nullptr, 0);
            cout << "Група " << groupName << " була створена.\n";
        }
        else if (choice == 2) {
            Student student;
            cin >> student;

            if (group != nullptr) {
                group->addStudent(student);
                cout << "Студента додано.\n";
            }
            else {
                cout << "Група не створена.\n";
            }
        }
        else if (choice == 3) {
            string name;
            cout << "Ведіть імя студента: ";
            cin >> name;
            if (group != nullptr) {
                group->searchByName(name);
            }
            else {
                cout << "Група не створена.\n";
            }
        }
        else if (choice == 4) {
            string groupName;
            cout << "Ведіть нзаву групи: ";
            cin >> groupName;
            if (group != nullptr) {
                group->searchByGroupName(groupName);
            }
            else {
                cout << "Груп не створено.\n";
            }
        }
        else if (choice == 5) {
            string recordNumber;
            cout << "Введіть номер заліковки: ";
            cin >> recordNumber;
            if (group != nullptr) {
                group->searchByRecordNumber(recordNumber);
            }
            else {
                cout << "Груп не створено.\n";
            }
        }
        else if (choice == 6) {
            Address address;
            cout << "Введіть адресу: ";
            cin >> address;
            if (group != nullptr) {
                group->searchByAddress(address);
            }
            else {
                cout << "Груп не створено.\n";
            }
        }
        else if (choice == 7) {
            string name;
            cout << "Введіть імя студента для видалення: ";
            cin >> name;
            if (group != nullptr) {
                group->removeStudent(name);
            }
            else {
                cout << "Груп не створено.\n";
            }
        }
        else if (choice == 0) {
            if (group != nullptr) {
                delete group;
            }
            break;
        }
        else {
            cout << "Немає такого варіанту\n";
        }
    }

    return 0;
}
