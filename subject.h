#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>

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

    friend ostream& operator<<(ostream& os, const Subject& subject);
    friend istream& operator>>(istream& is, Subject& subject);
};

#endif
