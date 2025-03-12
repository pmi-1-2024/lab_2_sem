#ifndef RECORDBOOK_H
#define RECORDBOOK_H

#include <iostream>
#include "Subject.h"

using namespace std;

class RecordBook {
private:
    int number;
    Subject* subjects;
    int subjectCount;

public:
    RecordBook();
    RecordBook(int number, int subjectCount);
    ~RecordBook();

    int getNumber() const;
    bool hasSubject(const string& subjectName) const;
    bool hasSemester(int semester) const;

    friend ostream& operator<<(ostream& os, const RecordBook& recordBook);
    friend istream& operator>>(istream& is, RecordBook& recordBook);
};

#endif
