#include "Student.h"
#include "Search.h"
#include "Menu.h"
#include "Group.h"
#include "File.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    writeStudentsToFile("students.txt");

    int studentCount;
    Student* students = nullptr;

    readStudentsFromFile("students.txt", students, studentCount);

    if (students == nullptr) {
        cout << "�� ������� ������� ��� �������� � �����. ����������� �������� ������." << endl;

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
    }

    Group groups[4] = {
        Group("��-43"),
        Group("��-11"),
        Group("���-12"),
        Group("���-24")
    };

    for (int i = 0; i < studentCount; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (students[i].getGroup() == groups[j].getName()) {
                groups[j].addStudent(students[i]);
            }
        }
    }

    handleMenu(students, studentCount, groups, 4);

    delete[] students;

    return 0;
}

