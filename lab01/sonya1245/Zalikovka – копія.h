#pragma once

#include "Subject.h"
#include <string>
using namespace std;

class Zalikovka {
public:
    string number;
    Subject subjects[5];
    int subjectCount;

    Zalikovka();

    void input();
    void output() const;
};

