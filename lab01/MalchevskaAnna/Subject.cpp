#include "Subject.h"

Subject::Subject() : name(""), semester(0), grade(0) {}

Subject::Subject(string name, int semester, int grade)
    : name(name), semester(semester), grade(grade) {}

ostream& operator<<(ostream& os, const Subject& subject) {
    os << "Subject: " << subject.name << ", Semester: " << subject.semester
        << ", Grade: " << subject.grade;
    return os;
}

istream& operator>>(istream& is, Subject& subject) {
    cout << "Enter subject name: ";
    is >> subject.name;
    cout << "Enter semester number: ";
    is >> subject.semester;
    cout << "Enter grade: ";
    is >> subject.grade;
    return is;
}