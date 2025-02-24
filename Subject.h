#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <string>
using namespace std;
class Subject {
private:
    string name;
    int semester;
    double grade;
public:
    Subject(string name = "", int semester = 0, double grade = 0.0)
        : name(name), semester(semester), grade(grade) {}

    friend ostream& operator<<(ostream& os, const Subject& subj);
    friend istream& operator>>(istream& is, Subject& subj);
};

#endif
