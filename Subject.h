#pragma once
#include <string>

using namespace std;

class Subject {
public:
    string name;
    int semester;
    int grade;

    Subject(string name = "", int semester = 0, int grade = 0);
    void input();
    void output() const;
};
