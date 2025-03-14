#pragma once
#include <iostream>
using namespace std;

class Subject {
private:
    string name;
    int semester;
    int grade;

public:
    Subject();
    Subject(string name, int semester, int grade);

    friend ostream& operator<<(ostream& os, const Subject& subject);
    friend istream& operator>>(istream& is, Subject& subject);
};