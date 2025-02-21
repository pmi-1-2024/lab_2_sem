#include "Student.h"
#include "Search.h"
#include "Menu.h"
#include "File.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
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

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    writeStudentsToFile("students.txt");

    int studentCount;
    Student* students = nullptr;

    readStudentsFromFile("students.txt", students, studentCount);

    if (students != nullptr) {
        handleMenu(students, studentCount);
        delete[] students;
    }
    else {
        cout << "�� ������� ������� ��� �������� � �����." << endl;

        studentCount = 3;
        students = new Student[studentCount];

        Zalik zalik1(73528, 3);
        zalik1.setSubject(0, Subject("������������ �����", 1, 90.0f));
        zalik1.setSubject(1, Subject("Գ���� �� ����������", 2, 85.0f));
        zalik1.setSubject(2, Subject("ճ��� ������", 1, 88.0f));
        students[0] = Student("����� �����", Adress(79070, "����", "��������� 6"), "��-43", zalik1);

        Zalik zalik2(56741, 2);
        zalik2.setSubject(0, Subject("����������㳿", 1, 92.0f));
        zalik2.setSubject(1, Subject("������", 2, 80.0f));
        students[1] = Student("���� �������", Adress(20220, "���", "���������� 2"), "��-11", zalik2);

        Zalik zalik3(86933, 4);
        zalik3.setSubject(0, Subject("������������ �����", 1, 75.0f));
        zalik3.setSubject(1, Subject("Գ���� �� ����������", 2, 82.0f));
        zalik3.setSubject(2, Subject("ճ��� ������", 1, 78.0f));
        zalik3.setSubject(3, Subject("��������", 2, 85.0f));
        students[2] = Student("����� �����", Adress(32030, "�����", "��������� 21"), "�̳-22", zalik3);

        handleMenu(students, studentCount);

        delete[] students;
    }

    return 0;
}
