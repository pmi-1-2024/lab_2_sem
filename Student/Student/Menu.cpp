#include "Menu.h"
#include "Search.h"
#include <iostream>
using namespace std;

void displayMenu() {
    cout << "���� ������:" << endl;
    cout << "1. ����� �� ��'��" << endl;
    cout << "2. ����� �� ������" << endl;
    cout << "3. ����� �� ������� ��������" << endl;
    cout << "4. ����� �� �������" << endl;
    cout << "5. ����� �� ���������" << endl;
    cout << "6. ����� �� ���������" << endl;
    cout << "0. �����" << endl;
}

void handleMenu(Student* students, int studentCount) {
    int choice;
    do {
        displayMenu();
        cout << "������� �����: ";
        cin >> choice;

        string inputStr;
        int inputInt;

        switch (choice) {
        case 1:
            cout << "������ ��'�: ";
            cin >> ws;
            getline(cin, inputStr);
            cout << "������� ��'�: " << inputStr << endl;
            findByName(students, studentCount, inputStr);
            break;
        case 2:
            cout << "������ �����: ";
            cin >> ws;
            getline(cin, inputStr);
            cout << "������� �����: " << inputStr << endl;
            findByGroup(students, studentCount, inputStr);
            break;
        case 3:
            cout << "������ ����� ��������: ";
            cin >> inputInt;
            cout << "�������� ����� ��������: " << inputInt << endl;
            findByZalik(students, studentCount, inputInt);
            break;
        case 4:
            cout << "������ ������� ������: ";
            cin >> ws;
            getline(cin, inputStr);
            cout << "������� ������� ������: " << inputStr << endl;
            findByAdress(students, studentCount, inputStr);
            break;
        case 5:
            cout << "������ ����� ��������: ";
            cin >> ws;
            getline(cin, inputStr);
            cout << "������� ����� ��������: " << inputStr << endl;
            findBySubject(students, studentCount, inputStr);
            break;
        case 6:
            cout << "������ �������: ";
            cin >> inputInt;
            cout << "�������� �������: " << inputInt << endl;
            findBySem(students, studentCount, inputInt);
            break;
        case 0:
            cout << "�����" << endl;
            break;
        default:
            cout << "������� ����, ��������� �� ���." << endl;
        }
    } while (choice != 0);
}


