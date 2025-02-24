#include "Predmet.h"
#include <iostream>
using namespace std;

Predmet::Predmet(){}
Predmet::Predmet(string n,string s,int g): name(n), semester(s), grade(g){}

string Predmet::GetName() const {
    return name;
}
string Predmet::GetSem() const {
    return semester;
}
int Predmet::GetGrade()const {
    return grade;
}

istream& operator>>(istream& is, Predmet& pred)
{
    cout << "\nEnter subject: ";
    is >> pred.name;
    cout << "\nEnter Semestr: ";
    is >> pred.semester;
    cout << "\nEnter Grade: ";
    is >> pred.grade;
    return is;
}
ostream& operator<<(ostream& os, const Predmet& pred) {
    os << "\nSubject: " << pred.name;
    os << "\nSemester: " << pred.semester;
    os << "\nGrade: " << pred.grade;
    return os;
}
