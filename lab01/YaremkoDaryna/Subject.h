#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <string>
using namespace std;

class Subject {
private:
    string name;
    int semester, grade;
public:
    Subject(string name = "", int semester = 0, int grade = 0)
        : name(name), semester(semester), grade(grade) {
    }

    void display() const {
        cout << name << " (Семестр " << semester << "): " << grade << endl;
    }

    string getName() const { return name; }
    int getSemester() const { return semester; }
    int getGrade() const { return grade; }
};
#endif