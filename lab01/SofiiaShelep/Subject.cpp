#include "Subject.h"
#include <iostream>

Subject::Subject() : name(""), semester(0), grade(0) {}

Subject::Subject(string n, int s, int g) : name(n), semester(s), grade(g) {}

void Subject::setName(string n) { name = n; }
void Subject::setSemester(int s) { semester = s; }
void Subject::setGrade(int g) { grade = g; }

string Subject::getName() const { return name; }
int Subject::getSemester() const { return semester; }
int Subject::getGrade() const { return grade; }

ostream& operator<<(ostream& os, const Subject& sub)
{
    os << sub.name << " " << sub.semester << " " << sub.grade;
    return os;
}

istream& operator>>(istream& is, Subject& sub)
{
    is >> sub.name >> sub.semester >> sub.grade;
    return is;
}