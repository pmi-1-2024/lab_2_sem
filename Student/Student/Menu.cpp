#include "Menu.h"
#include "Search.h"
#include <iostream>
using namespace std;

void displayMenu() {
    cout << "Меню пошуку:" << endl;
    cout << "1. Пошук за ім'ям" << endl;
    cout << "2. Пошук за групою" << endl;
    cout << "3. Пошук за номером заліковки" << endl;
    cout << "4. Пошук за адресою" << endl;
    cout << "5. Пошук за предметом" << endl;
    cout << "6. Пошук за семестром" << endl;
    cout << "0. Вихід" << endl;
}

void handleMenu(Student* students, int studentCount) {
    int choice;
    do {
        displayMenu();
        cout << "Виберіть опцію: ";
        cin >> choice;

        string inputStr;
        int inputInt;

        switch (choice) {
        case 1:
            cout << "Введіть ім'я: ";
            cin >> ws;
            getline(cin, inputStr);
            cout << "Введене ім'я: " << inputStr << endl;
            findByName(students, studentCount, inputStr);
            break;
        case 2:
            cout << "Введіть групу: ";
            cin >> ws;
            getline(cin, inputStr);
            cout << "Введена група: " << inputStr << endl;
            findByGroup(students, studentCount, inputStr);
            break;
        case 3:
            cout << "Введіть номер заліковки: ";
            cin >> inputInt;
            cout << "Введений номер заліковки: " << inputInt << endl;
            findByZalik(students, studentCount, inputInt);
            break;
        case 4:
            cout << "Введіть частину адреси: ";
            cin >> ws;
            getline(cin, inputStr);
            cout << "Введена частина адреси: " << inputStr << endl;
            findByAdress(students, studentCount, inputStr);
            break;
        case 5:
            cout << "Введіть назву предмета: ";
            cin >> ws;
            getline(cin, inputStr);
            cout << "Введена назва предмета: " << inputStr << endl;
            findBySubject(students, studentCount, inputStr);
            break;
        case 6:
            cout << "Введіть семестр: ";
            cin >> inputInt;
            cout << "Введений семестр: " << inputInt << endl;
            findBySem(students, studentCount, inputInt);
            break;
        case 0:
            cout << "Вихід" << endl;
            break;
        default:
            cout << "Невірний вибір, спробуйте ще раз." << endl;
        }
    } while (choice != 0);
}


