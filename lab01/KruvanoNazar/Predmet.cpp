#include "Predmet.h"
#include <iostream>
using namespace std;

Predmet::Predmet(): name("noname"),semester("nosem"),grade(0){}
Predmet::Predmet(string n,string s,int g): name(n), semester(s), grade(g){}

/*Predmet::Predmet(const Predmet& sub)
{
    name = sub.name;
    semester = sub.semester;
    grade = sub.grade;
}*/

string Predmet::GetName() const {
    return name;
}
string Predmet::GetSem() const {
    return semester;
}
int Predmet::GetGrade()const {
    return grade;
}

Predmet& Predmet::operator=(const Predmet& pred)
{
    if (this == &pred) {
        return *this;
    }
    name = pred.name;
    semester = pred.semester;
    grade = pred.grade;
    return*this;
}

istream& operator>>(istream& is, Predmet& pred)
{
    is >> pred.name;
    is >> pred.semester;
    is >> pred.grade;
    return is;
}
ostream& operator<<(ostream& os, const Predmet& pred) {
    os << "\nSubject: " << pred.name;
    os << "\nSemester: " << pred.semester;
    os << "\nGrade: " << pred.grade;
    return os;
}
