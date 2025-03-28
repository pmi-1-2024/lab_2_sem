#pragma once
#include <string>
#include <iostream>
using namespace std;

class Subject {
private:
    string name;
    int semester;
    int grade;

public:
    Subject();
    Subject(const string& name, int semester, int grade);

    string getName() const;
    int getSemester() const;
    int getGrade() const;

    friend ostream& operator<<(ostream& os, const Subject& subj);
    friend istream& operator>>(istream& is, Subject& subj);
};