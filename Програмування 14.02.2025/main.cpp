#include "Functions.h"
#include <windows.h>
#include <iostream>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string filename = "students.txt";
    int choice;

    do {
        cout << "\nМеню:" << endl;
        cout << "1. Вивести всіх студентів" << endl;
        cout << "2. Пошук студента за ім'ям" << endl;
        cout << "3. Пошук студента за групою" << endl;
        cout << "4. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            readStudentsFromFile(filename);
        }
        else if (choice == 2) {
            string name;
            cout << "Введіть ім'я студента: ";
            cin.ignore();
            getline(cin, name);
            searchStudentByName(filename, name);
        }
        else if (choice == 3) {
            string group;
            cout << "Введіть назву групи: ";
            cin.ignore();
            getline(cin, group);
            searchStudentByGroup(filename, group);
        }
    } while (choice != 4);

    cout << "Програма завершена." << endl;
    return 0;
}
