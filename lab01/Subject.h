#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
using namespace std;

class Subject {
private:
    string name;
    int semester;
    double grade;

public:
    Subject() : name(""), semester(0), grade(0) {}
    Subject(string n, int sem, double g) : name(n), semester(sem), grade(g) {}

    double getGrade() const { return grade; }

    friend ostream& operator<<(ostream& out, const Subject& sub);
    friend istream& operator>>(istream& in, Subject& sub);
};

#endif
