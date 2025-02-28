#pragma once
#include "Subject.h"

class Zalikovka {
public:
    int number;
    Subject* subjects;
    int subjectCount;

    Zalikovka(int number = 0, int subjectCount = 0);
    ~Zalikovka();
    void output() const;
};