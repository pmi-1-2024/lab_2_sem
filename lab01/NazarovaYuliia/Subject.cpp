#include "Subject.h"
#include <iostream>
using namespace std;

Subject::Subject():name(""), semester(0), grade(0){}
Subject::Subject(string name, int semester, int grade)
    : name(name), semester(semester), grade(grade) {
}

string Subject::getName() const { return name; }
int Subject::getSemester() const { return semester; }
int Subject::getGrade() const { return grade; }

ostream& operator<<(ostream& os, const Subject& subj) {
    os << "Name: " << subj.name << ", Semester: " << subj.semester 
       << ", Grade: " << subj.grade;
    return os;
}

istream& operator>>(istream& is, Subject& subj) {
    cout << "Enter subject name: ";
    is.ignore();
    getline(is, subj.name);

    cout << "Enter semester: ";
    is >> subj.semester;

    cout << "Enter grade: ";
    is >> subj.grade;

    return is;
}