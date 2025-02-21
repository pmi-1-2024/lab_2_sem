#include <iostream>
#include <windows.h>
#include <vector>
#include "Student.h"

using namespace std;

// ������� ��� ������ �������� �� ��������� ������
void searchByGradeRange(const vector<Student>& students, double minGrade, double maxGrade) {
    cout << "\n�������� � �������� � ������� [" << minGrade << ", " << maxGrade << "]:" << endl;
    bool found = false;

    for (const auto& student : students) {
        bool hasGradeInRange = false;
        for (const auto& subject : student.recordBook.subjects) {
            if (subject.grade >= minGrade && subject.grade <= maxGrade) {
                hasGradeInRange = true;
                break;
            }
        }
        if (hasGradeInRange) {
            student.display();
            cout << "--------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "���� �������� � �������� � ��������� �������." << endl;
    }
}

int main() {
    SetConsoleOutputCP(65001); // ��������� ��������� UTF-8 ��� ������
    SetConsoleCP(65001);       // ��������� ��������� UTF-8 ��� ��������
    setlocale(LC_ALL, "");     // ����������

    vector<Student> students = {
        Student("����� ��������", Address("79000", "����", "���. �������� 10"), "��-2023", RecordBook("123001")),
        Student("��������� ��������", Address("02000", "���", "��. �������� 15"), "��-2023", RecordBook("123002")),
        Student("���� ������", Address("58000", "�������", "���. ������� 5"), "ʲ-2023", RecordBook("123003")),
        Student("����� ��������", Address("65000", "�����", "���������� ������ 33"), "��-2022", RecordBook("123004")),
        Student("������ ���������", Address("49000", "�����", "�����. ������� 25"), "��-2021", RecordBook("123005")),
        Student("������ �������", Address("76000", "�����-���������", "���. ������������ 7"), "ʲ-2020", RecordBook("123006")),
        Student("��������� ���������", Address("61000", "�����", "����������� �����. 40"), "��-2023", RecordBook("123007")),
        Student("����� ��������", Address("46000", "��������", "���. ������ 12"), "��-2023", RecordBook("123008")),
        Student("������ ����������", Address("21000", "³�����", "���. ������� 5"), "ʲ-2022", RecordBook("123009")),
        Student("�������� �������", Address("40000", "����", "���. �������������� 2"), "��-2021", RecordBook("123010"))
    };

    // ������ �������� ��� ������� ��������
    students[0].recordBook.addSubject(Subject("����������", 1, 85));
    students[0].recordBook.addSubject(Subject("�������������", 2, 90));

    students[1].recordBook.addSubject(Subject("Գ����", 1, 80));
    students[1].recordBook.addSubject(Subject("���������", 2, 88));

    students[2].recordBook.addSubject(Subject("��������� ����������", 1, 92));
    students[2].recordBook.addSubject(Subject("���� �����", 2, 89));

    students[3].recordBook.addSubject(Subject("˳���� �������", 1, 75));
    students[3].recordBook.addSubject(Subject("����'����� �����", 2, 70));

    students[4].recordBook.addSubject(Subject("��������� �������", 1, 95));
    students[4].recordBook.addSubject(Subject("����� �����������", 2, 82));

    students[5].recordBook.addSubject(Subject("���-�������������", 1, 65));
    students[5].recordBook.addSubject(Subject("��������� ��������", 2, 78));

    students[6].recordBook.addSubject(Subject("�������� �������������", 1, 72));
    students[6].recordBook.addSubject(Subject("������� ��������", 2, 98));

    students[7].recordBook.addSubject(Subject("��������� �������", 1, 85));
    students[7].recordBook.addSubject(Subject("������� ��������", 2, 91));

    students[8].recordBook.addSubject(Subject("ʳ����������", 1, 60));
    students[8].recordBook.addSubject(Subject("Big Data", 2, 88));

    students[9].recordBook.addSubject(Subject("Գ�������", 1, 69));
    students[9].recordBook.addSubject(Subject("�������������", 2, 77));

    // ��������� ��� ��������
    cout << "������ ��� ��������:\n";
    for (const auto& student : students) {
        student.display();
        cout << "--------------------------" << endl;
    }

    // ����� �� ��������� ������
    double minGrade, maxGrade;
    cout << "\n������ ������� ������ (�������� ������ - ����������� ������): ";
    cin >> minGrade >> maxGrade;

    searchByGradeRange(students, minGrade, maxGrade);

    return 0;
}