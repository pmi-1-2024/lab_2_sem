#include <iostream>
#include "Student.h"

using namespace std;

void searchByResidence(const Student students[], int count, const string& residence) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].residence == residence) {
            cout << "�������� ��������, �� ������� � " << residence << "!" << endl;
            printStudentInfo(students[i]);
            found = true;
        }
    }
    if (!found) cout << "̳��� ���������� " << residence << " �� ��������!" << endl;
}
