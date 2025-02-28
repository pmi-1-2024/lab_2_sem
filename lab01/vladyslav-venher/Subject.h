#pragma once

#include <iostream>
#include <string>
using namespace std;

class Subject {
public:
    string name;
    int semester;
    int grade;

    Subject();
    void output() const;
};