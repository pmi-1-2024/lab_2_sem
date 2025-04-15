#include "Subject.h"

Subject::Subject() : name(""), semester(0), grade(0) {}

Subject::Subject(string n, int sem, int g) : name(n), semester(sem), grade(g) {}

string Subject::GetName() const
{
    return name;
}

int Subject::GetSemester() const
{
    return semester;
}

int Subject::GetGrade() const
{
    return grade;
}

istream& operator>>(istream& in, Subject& sub) {
    cout << "Enter subject name: ";
    in >> sub.name;
    cout << "Enter semester: ";
    in >> sub.semester;
    cout << "Enter grade: ";
    in >> sub.grade;
    return in;
}

ostream& operator<<(ostream& out, const Subject& sub) {
    out << "Subject: " << sub.name << ", Semester: " << sub.semester << ", Grade: " << sub.grade;
    return out;
}
