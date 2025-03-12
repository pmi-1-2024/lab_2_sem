#include <iostream>
#include "Student.h"

using namespace std;

void searchByPostalCode(const Student students[], int count, const string& postal_code) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].postal_code == postal_code) {
            cout << "�������� �������� � �������� �������� " << postal_code << "!" << endl;
            printStudentInfo(students[i]);
            found = true;
        }
    }
    if (!found) cout << "�������� ������ " << postal_code << " �� ��������!" << endl;
}
