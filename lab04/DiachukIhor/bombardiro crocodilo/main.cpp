#include <iostream>
#include "Student_Manager.h"
#include <windows.h>

using namespace std;

void menu() {
    cout << "\n����:" << endl;
    cout << "1)�������� ��������" << endl;
    cout << "2)�������� ��������" << endl;
    cout << "3)������ ��������" << endl;
    cout << "4)������� ����������" << endl;
    cout << "5)�������� ��� ��������" << endl;
    cout << "0)�����" << endl;
    cout << "��� ����: ";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    cout << "����������� ������ 4" << endl;
    cout << "������� ������� ����� �̲11 ����� ����" << endl << endl;
    cout << "���������� �� ����:" << endl;
    cout << "��� ��� ������ ������� ��� ��������� ���������� �� ��������� ��������� �������� �����." << endl;

    Student_Manager manager;
    int choice;

    do {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string name;
            int id;
            cout << "������ ��'� ��������: ";
            getline(cin, name);
            cout << "������ ID ��������: ";
            cin >> id;
            manager.addStudent(Student(name, id));
            cout << "�������� ���������.\n";
            break;
        }
        case 2: {
            string name;
            int id;
            cout << "������ ��'� ��� ����������� ��������: ";
            getline(cin, name);
            cout << "������ ID ��������: ";
            cin >> id;
            manager.removeStudent(Student(name, id));
            break;
        }
        case 3: {
            string name;
            int id;
            cout << "������ ��'� ��������: ";
            getline(cin, name);
            cout << "������ ID ��������: ";
            cin >> id;
            manager.findStudent(Student(name, id));
            break;
        }
        case 4: {
            string oldName, newName;
            int oldId, newId;
            cout << "������ ��'� ��������: ";
            getline(cin, oldName);
            cout << "������ ID ��������: ";
            cin >> oldId;
            cin.ignore();
            cout << "������ ���� ��'� ��������: ";
            getline(cin, newName);
            cout << "������ ����� ID ��������: ";
            cin >> newId;
            manager.updateStudent(Student(oldName, oldId), Student(newName, newId));
            break;
        }
        case 5:
            manager.displayAll();
            break;
        case 0:
            cout << "�����." << endl;
            break;
        default:
            cout << "���������� �� ���" << endl;
        }
    } while (choice != 0);

    return 0;
}
