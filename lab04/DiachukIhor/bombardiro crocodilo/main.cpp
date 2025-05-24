#include <iostream>
#include "Student_Manager.h"
#include <windows.h>

using namespace std;

void menu() {
    cout << "\n����:" << endl;
    cout << "1) �������� ��������" << endl;
    cout << "2) �������� ��������" << endl;
    cout << "3) ������ ��������" << endl;
    cout << "4) ������� ����������" << endl;
    cout << "5) �������� ��� ��������" << endl;
    cout << "0) �����" << endl;
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
            Student student;
            cin >> student;
            manager.addStudent(student);
            cout << "�������� ���������.\n";
            break;
        }
        case 2: {
            Student student;
            cin >> student;
            manager.removeStudent(student);
            break;
        }
        case 3: {
            Student student;
            cin >> student;
            manager.findStudent(student);
            break;
        }
        case 4: {
            Student oldStudent, newStudent;
            cout << "������ ���� ��� ��������:\n";
            cin >> oldStudent;
            cout << "������ ��� ��� ��������:\n";
            cin >> newStudent;
            manager.updateStudent(oldStudent, newStudent);
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