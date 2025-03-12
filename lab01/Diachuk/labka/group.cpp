#include <iostream>
#include "Student.h"

using namespace std;

void searchByGroup(const Student students[], int count, const string& group) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].group == group) {
            cout << "�������� �������� � ���� " << group << "!" << endl;
            printStudentInfo(students[i]);
            found = true;
        }
    }
    if (!found) cout << "����� " << group << " �� ��������!" << endl;
}
