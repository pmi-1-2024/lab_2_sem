#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "SearchByName.h"
#include "SearchByGroup.h"
#include "SearchBySubject.h"
#include "SearchByResidence.h"
#include "SearchByGrade.h"
#include "SearchByPostalCode.h"

using namespace std;

const int MAX_STUDENTS = 100;

int readStudentsFromFile(const string& filename, Student students[], int maxStudents) {
    ifstream file(filename);
    if (!file) {
        cerr << "�� ������� ������� ����!" << endl;
        return 0;
    }

    int count = 0;
    while (count < maxStudents && file >> students[count].name >> students[count].group >> students[count].subject
        >> students[count].residence >> students[count].grade >> students[count].postal_code) {
        count++;
    }
    file.close();
    return count;
}

void printStudentInfo(const Student& s) {
    s.print();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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
            searchByName(students, studentCount, input);
            break;
        case 2:
            cout << "������ ����� ��� ������: ";
            cin >> input;
            searchByGroup(students, studentCount, input);
            break;
        case 3:
            cout << "������ ������� ��� ������: ";
            cin >> input;
            searchBySubject(students, studentCount, input);
            break;
        case 4:
            cout << "������ ���� ���������� ��� ������: ";
            cin >> input;
            searchByResidence(students, studentCount, input);
            break;
        case 5:
            cout << "������ ������ ��� ������: ";
            cin >> grade;
            searchByGrade(students, studentCount, grade);
            break;
        case 6:
            cout << "������ �������� ������ ��� ������: ";
            cin >> input;
            searchByPostalCode(students, studentCount, input);
            break;
        case 7:
            for (int i = 0; i < studentCount; i++) {
                printStudentInfo(students[i]);
            }
            break;
        }
    } while (choice != 0);

    return 0;
}
