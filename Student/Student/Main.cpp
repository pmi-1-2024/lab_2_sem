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
    file << "79210\n";
    file << "��������\n";
    file << "��������� 5\n";
    file << "���-12\n";
    file << "11232 3\n";
    file << "��������� ����������\n";
    file << "5 17.0\n";
    file << "�������\n";
    file << "2 55.0\n";
    file << "����������\n";
    file << "4 81.0\n";
    file << "����� ����\n";
    file << "21231\n";
    file << "���������\n";
    file << "���������� 61\n";
    file << "Ͳ-45\n";
    file << "91312 2\n";
    file << "����������������\n";
    file << "6 32.0\n";
    file << "���������\n";
    file << "2 12.0\n";
    file << "���� �����\n";
    file << "30120\n";
    file << "���� ������\n";
    file << "������ 87\n";
    file << "ǲ�-23\n";
    file << "67890 4\n";
    file << "Գ���������\n";
    file << "1 75.0\n";
    file << "Գ����\n";
    file << "6 21.0\n";
    file << "ճ��� ������\n";
    file << "3 28.0\n";
    file << "��������\n";
    file << "4 56.0\n";

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
        zalik1.setSubject(0, Subject("������������ �����", 5, 91.0f));
        zalik1.setSubject(1, Subject("Գ���� �� ����������", 2, 43.0f));
        zalik1.setSubject(2, Subject("ճ��� ������", 3, 82.0f));
        students[0] = Student("����� �����", Adress(79070, "����", "��������� 6"), "��-43", zalik1);

        Zalik zalik2(56741, 2);
        zalik2.setSubject(0, Subject("����������㳿", 5, 95.0f));
        zalik2.setSubject(1, Subject("������", 1, 20.0f));
        students[1] = Student("���� �������", Adress(20220, "���", "���������� 2"), "��-11", zalik2);

        Zalik zalik3(86933, 4);
        zalik3.setSubject(0, Subject("������������ �����", 1, 55.0f));
        zalik3.setSubject(1, Subject("Գ���� �� ����������", 4, 22.0f));
        zalik3.setSubject(2, Subject("ճ��� ������", 1, 23.0f));
        zalik3.setSubject(3, Subject("��������", 3, 65.0f));
        students[2] = Student("����� �����", Adress(32030, "�����", "��������� 21"), "�̳-22", zalik3);

        handleMenu(students, studentCount);

        delete[] students;
    }

    return 0;
}
