#include "File.h"
#include "Group.h"
#include <fstream>
#include <iostream>
using namespace std;

void writeStudentsToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "�� ������� ������� ���� ��� ������!" << endl;
        return;
    }

    file << "3\n";
    file << "���� ������\n";
    file << "28310\n";
    file << "�������\n";
    file << "�������� 23\n";
    file << "���-12\n";
    file << "32553 3\n";
    file << "���������\n";
    file << "3 32.0\n";
    file << "Գ�������\n";
    file << "3 67.0\n";
    file << "����������\n";
    file << "6 23.0\n";
    file << "����� �������\n";
    file << "12454\n";
    file << "�������\n";
    file << "������������� 10\n";
    file << "���-24\n";
    file << "43218 2\n";
    file << "ճ������ ������\n";
    file << "2 21.0\n";
    file << "������ ��������\n";
    file << "6 23.0\n";
    file << "���� �����\n";
    file << "30232\n";
    file << "�������\n";
    file << "���-��������� 90\n";
    file << "��-23\n";
    file << "32421 4\n";
    file << "������������� �������\n";
    file << "4 46.0\n";
    file << "�������������\n";
    file << "1 23.0\n";
    file << "�������\n";
    file << "5 12.0\n";
    file << "��������\n";
    file << "4 81.0\n";

    file.close();
    cout << "��� ������ ������� � ���� " << filename << endl;
}

void readStudentsFromFile(const string& filename, Student*& students, int& count) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "�� ������� ������� ����!" << endl;
        return;
    }

    file >> count;
    if (count <= 0) {
        cout << "������� ������ ����� ��� ������� ��������." << endl;
        return;
    }

    students = new Student[count];
    if (students == nullptr) {
        cout << "�� ������� ������� ���'��� ��� ��������." << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        file >> students[i];
        if (file.fail()) {
            cout << "������� ���������� ����� ��������." << endl;
            delete[] students;
            students = nullptr;
            return;
        }
    }

    file.close();
}
