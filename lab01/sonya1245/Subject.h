#pragma once

#include <iostream>
#include <string>

using namespace std;

class Subject {
private:
    string name;
    int semester;
    double grade;

public:
    Subject();
    friend istream& operator>>(istream& in, Subject& subject);
    friend ostream& operator<<(ostream& out, const Subject& subject);
    const string& getName() const;
    int getSemester() const;
};
