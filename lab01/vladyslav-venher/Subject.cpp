#include "Subject.h"
using namespace std;

Subject::Subject() : name(""), semester(0), grade(0) {}

Subject::Subject(string name, string semester, int grade) : name(name), semester(semester), grade(grade) {}

string Subject::getName() const {
    return name;
}

string Subject::getSemester() const {
    return semester;
}

int Subject::getGrade() const {
    return grade;
}

ostream& operator<<(ostream& os, const Subject& subject) {
    os << subject.name << " " << subject.semester << " " << subject.grade;
    return os;
}

istream& operator>>(istream& is, Subject& subject) {
    is >> subject.name >> subject.semester >> subject.grade;
    return is;
}