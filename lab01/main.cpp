#include <iostream>
#include <windows.h>
#include "Student.h"
#include "InitData.h"

using namespace std;

void searchStudentsByGrade(const Student students[], int studentCount, double minGrade, double maxGrade) {
    cout << "\nСтуденти з оцінками в діапазоні [" << minGrade << ", " << maxGrade << "]:" << endl;
    bool found = false;

    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < students[i].getRecordBook().getSubjectCount(); j++) {
            double grade = students[i].getRecordBook().getSubject(j).getGrade();
            if (grade >= minGrade && grade <= maxGrade) {
                cout << students[i] << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "Студентів із такими оцінками не знайдено.\n";
    }
}

int main() {
    SetConsoleCP(65001);
    setlocale(LC_ALL, "");

    const int MAX_STUDENTS = 10;
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    initializeStudents(students, studentCount);

    cout << "\nСписок студентів:\n";
    for (int i = 0; i < studentCount; i++) {
        cout << students[i] << endl;
    }

    double minGrade, maxGrade;
    cout << "\nВведіть мінімальну оцінку: ";
    cin >> minGrade;
    cout << "Введіть максимальну оцінку: ";
    cin >> maxGrade;

    searchStudentsByGrade(students, studentCount, minGrade, maxGrade);

    return 0;
}
