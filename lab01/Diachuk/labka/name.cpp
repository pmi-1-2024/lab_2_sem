#include <iostream>
#include "Student.h"

using namespace std;

void searchByName(const Student students[], int count, const string& name) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].name == name) {
            cout << "�������� ��������!" << endl;
            printStudentInfo(students[i]);
            found = true;
        }
    }
    if (!found) cout << "�������� � ��'�� " << name << " �� ��������!" << endl;
}
