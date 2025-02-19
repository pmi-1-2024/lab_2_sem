#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
using namespace std;

class Subject {
private:
    string name;
    int semester;
    int grade;

public:
    Subject(string name = "", int semester = 0, int grade = 0);
    string getName() const;
    int getSemester() const;
    int getGrade() const;
};

#endif




