#include "Subject.h"
Subject::Subject():name("none"), semester(0), grade(0){}
Subject::Subject(string n, int s, double g) : name(n), semester(s), grade(g) {}

string Subject::getName() const { return name; }

int Subject::getSemester() const { return semester; }

void Subject::setAll(string _name, int _semester, double _grade)
{
    this->name = _name;
    this->semester = _semester;
    this->grade = _grade;
}

void Subject::display(ostream& os) const {
    cout << "Subject: " << name << ", Semester: " << semester << ", Grade: " << grade << endl;
}

void Subject::read(istream& is)
{
    is >> this->name >> this->semester >> this->grade;
}

istream& operator>>(istream& is, Subject& s)
{
    s.read(is);
    return is;
}

ostream& operator<<(ostream& os, Subject& s)
{
    s.display(os);
    return os;
}
