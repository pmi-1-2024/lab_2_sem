#include "Subject.h"

Subject::Subject() : name(""), semester(0), grade(0.0) {}

istream& operator>>(istream& in, Subject& subject) {
    cout << "Enter subject name: ";
    in.ignore(); 
    getline(in, subject.name); 
    cout << "Enter semester: ";
    in >> subject.semester;
    cout << "Enter grade: ";
    in >> subject.grade;
    return in;
}

ostream& operator<<(ostream& out, const Subject& subject) {
    out << "Subject: " << subject.name << ", Semester: " << subject.semester << ", Grade: " << subject.grade;
    return out;
}

const string& Subject::getName() const {
    return name;
}

int Subject::getSemester() const {
    return semester;
}