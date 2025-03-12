#include <iostream>
#include "Student.h"

using namespace std;

void searchByGrade(const Student students[], int count, double grade) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].grade == grade) {
            cout << "�������� �������� � ������� " << grade << "!" << endl;
            printStudentInfo(students[i]);
            found = true;
        }
    }
    if (!found) cout << "������ " << grade << " �� ��������!" << endl;
}
