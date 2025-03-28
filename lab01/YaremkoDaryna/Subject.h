#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
using namespace std;

class Subject {
private:
    string name, semester;
    int grade;
public:
    Subject() : name(""), semester(""), grade(0) {}
    Subject(string name, string semester, int grade)
        : name(name), semester(semester), grade(grade) {
    }

    string getName() const { return name; }
    string getSemester() const { return semester; }
    int getGrade() const { return grade; }

    friend istream& operator>>(istream& is, Subject& subject) {
        is >> subject.name >> subject.semester >> subject.grade;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Subject& subject) {
        os << subject.name << " " << subject.semester << " " << subject.grade;
        return os;
    }
};
#endif