#pragma once

#include <string>
using namespace std;

class Subject {
public:
    string name;
    int semester;
    int grade;

    Subject();
    Subject(string name, int semester, int grade);

    void input();
    void output() const;
};
