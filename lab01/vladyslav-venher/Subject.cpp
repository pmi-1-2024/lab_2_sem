#include "Subject.h"
using namespace std;

Subject::Subject() : name(""), semester(0), grade(0) {}
Subject::Subject(string n, int sem, int g) : name(n), semester(sem), grade(g) {}

ostream& operator<<(ostream& os, const Subject& s) {
    os << s.name << " " << s.semester << " " << s.grade;
    return os;
}

istream& operator>>(istream& is, Subject& s) {
    is >> ws;
    getline(is, s.name, ' ');
    is >> s.semester >> s.grade;
    return is;
}