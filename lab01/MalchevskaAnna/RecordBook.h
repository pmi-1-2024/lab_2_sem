#pragma once
#include <string>
#include "Subject.h"

using namespace std;

class RecordBook {
public:
    string number;
    Subject* subjects;
    int subjectCount;
    RecordBook(string number = "", int subjectCount = 0);
    ~RecordBook();
    void input();
    void output() const;
};
