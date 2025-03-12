#include "Functions.h"
#include <iostream>
using namespace std;


void readFromFile(ifstream& file, int& studentCount, Student*& students) {
    if (!file.is_open()) {
        cout << "�������: ���� �� ������� �������!" << endl;
        return;
    }

    file >> studentCount;

    if (students != nullptr) {
        delete[] students;
    }

    students = new Student[studentCount];

    for (int i = 0; i < studentCount; i++) {
        file >> students[i];
    }
}


void firstMenu() {
    cout << "���� ������:" << endl;
    cout << "1. �� ��'��" << endl;
    cout << "2. �� �������" << endl;
    cout << "3. �� ������" << endl;
    cout << "4. �� ������� ������� ������" << endl;
    cout << "5. �� ���������" << endl;
    cout << "6. �� ���������" << endl;
    cout << "7. *���� ��������� �����*" << endl;
    cout << "��� ����: ";
}

void secondMenu() {
    cout << "���� ��������� �����:" << endl;
    cout << "1. �������� �����" << endl;
    cout << "2. ������ ��������" << endl;
    cout << "3. �������� ��������" << endl;
    cout << "4. ����� �� �������" << endl;
    cout << "5. ����� �� ������� ������� ������" << endl;
    cout << "6. ����� �� ���������" << endl;
    cout << "0. �����" << endl;
    cout << "��� ����: ";
}
