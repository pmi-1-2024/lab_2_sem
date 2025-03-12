#include <iostream>
#include "Student.h"

using namespace std;

void searchBySubject(const Student students[], int count, const string& subject) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].subject == subject) {
            cout << "Знайдено студента по предмету " << subject << "!" << endl;
            printStudentInfo(students[i]);
            found = true;
        }
    }
    if (!found) cout << "Предмет " << subject << " не знайдено!" << endl;
}
