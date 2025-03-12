#pragma once
#include <iostream>
#include <string>
using namespace std;

class Subject {
private:
    string name;
    string semester;
    int grade;
public:
    Subject();
    Subject(string name, string semester, int grade);

    string getName() const;
    string getSemester() const;
    int getGrade() const;

    friend ostream& operator<<(ostream& os, const Subject& subject);
    friend istream& operator>>(istream& is, Subject& subject);
};