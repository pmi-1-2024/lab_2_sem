#include "Subject.h"

Subject::Subject() : name(""), semester(0), grade(0) {}

Subject::Subject(const string& name, int semester, int grade)
    : name(name), semester(semester), grade(grade) {}

Subject::Subject(const Subject& other)
    : name(other.name), semester(other.semester), grade(other.grade) {}

Subject& Subject::operator=(const Subject& other) {
    if (this != &other) {
        name = other.name;
        semester = other.semester;
        grade = other.grade;
    }
    return *this;
}

string Subject::getName() const { return name; }
int Subject::getSemester() const { return semester; }
int Subject::getGrade() const { return grade; }

ostream& operator<<(ostream& os, const Subject& subject) {
    os << subject.name << " (Semester: " << subject.semester << ", Grade: " << subject.grade << ")";
    return os;
}

istream& operator>>(istream& is, Subject& subject) {
    is >> subject.name >> subject.semester >> subject.grade;
    return is;
}
