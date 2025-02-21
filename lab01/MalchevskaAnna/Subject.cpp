#include "Subject.h"
#include <iostream>

Subject::Subject(string name, int semester, int grade)
    : name(name), semester(semester), grade(grade) {}

void Subject::input() {
    cout << "Enter subject name: ";
    cin >> name;
    cout << "Enter semester number: ";
    cin >> semester;
    cout << "Enter grade: ";
    cin >> grade;
}
void Subject::output() const {
    cout << "Subject: " << name << ", Semester: " << semester << ", Grade: " << grade << endl;
}
