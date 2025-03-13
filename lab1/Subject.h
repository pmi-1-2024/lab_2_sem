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
    Subject(string n, int sem, int g);

    friend istream& operator>>(istream& in, Subject& sub);
    friend ostream& operator<<(ostream& out, const Subject& sub);

    string GetName() const;
    int GetSemester() const;
    int GetGrade() const;
};

#endif

