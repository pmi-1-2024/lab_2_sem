#include <iostream>
#include "Student.h"

using namespace std;

void searchByName(const Student students[], int count, const string& name) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].name == name) {
            cout << "Знайдено студента!" << endl;
            printStudentInfo(students[i]);
            found = true;
        }
    }
    if (!found) cout << "Студента з ім'ям " << name << " не знайдено!" << endl;
}
