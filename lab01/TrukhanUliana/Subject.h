#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
using namespace std;

class Subject {
private:
    string name, semester;
    int grade;
public:
    Subject();
    Subject(string name, string semester, int grade);

    string getName() const;
    string getSemester() const;
    int getGrade() const;

    friend istream& operator>>(istream& is, Subject& subject);
    friend ostream& operator<<(ostream& os, const Subject& subject);
};
#endif 
