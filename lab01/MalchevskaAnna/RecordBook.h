#pragma once
#include "Subject.h"
#include <iostream>
using namespace std;

class RecordBook {
private:
    int number;
    Subject* subjects;
    int subjectCount;

public:
    RecordBook();
    RecordBook(int number, Subject* subjects, int subjectCount);
    ~RecordBook();

    int getNumber() const;
    void addSubject(const Subject& subject);
    friend ostream& operator<<(ostream& os, const RecordBook& recordBook);
    friend istream& operator>>(istream& is, RecordBook& recordBook);
};