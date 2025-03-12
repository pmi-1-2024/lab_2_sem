#include <windows.h>
#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int studentCount = readStudentsFromFile("students.txt", students, MAX_STUDENTS);

    if (studentCount == 0) {
        cout << "���� �������� � ����!" << endl;
        return 1;
    }

    int choice;
    string input;
    double grade;

    do {
        cout << "\n���� ������ �������� �� �������:" << endl;
        cout << "1. ����� �� ��'��" << endl;
        cout << "2. ����� �� ������" << endl;
        cout << "3. ����� �� ���������" << endl;
        cout << "4. ����� �� ����� ����������" << endl;
        cout << "5. ����� �� �������" << endl;
        cout << "6. ����� �� �������� ��������" << endl;
        cout << "7. ������� ��� ��������" << endl;
        cout << "0. �����" << endl;
        cout << "������� ������� ������ (0-7): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������ ��'� ��� ������: ";
            cin >> input;
            name(students, studentCount, input);
            break;
        case 2:
            cout << "������ ����� ��� ������: ";
            cin >> input;
            group(students, studentCount, input);
            break;
        case 3:
            cout << "������ ������� ��� ������: ";
            cin >> input;
            subject(students, studentCount, input);
            break;
        case 4:
            cout << "������ ���� ���������� ��� ������: ";
            cin >> input;
            address(students, studentCount, input);
            break;
        case 5:
            cout << "������ ������ ��� ������: ";
            cin >> grade;
            grade(students, studentCount, grade);
            break;
        case 6:
            cout << "������ �������� ������ ��� ������: ";
            cin >> input;
            postl(students, studentCount, input);
            break;
        case 7:
            cout << "�� ��������:" << endl;
            for (int i = 0; i < studentCount; ++i) {
                printStudentInfo(students[i]);
            }
            break;
        case 0:
            cout << "����� � ��������." << endl;
            break;
        default:
            cout << "������� ����! ��������� �� ���." << endl;
        }
    } while (choice != 0);

    return 0;
}
