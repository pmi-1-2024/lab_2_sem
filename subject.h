#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
using namespace std;

class Subject {
public:
    string name;
    int semester;
    double grade;

    Subject() {}
    Subject(string n, int sem, double g) : name(n), semester(sem), grade(g) {}
    void display() const;
};
#endif
