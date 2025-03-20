#ifndef RECORDBOOK_H
#define RECORDBOOK_H
#include <iostream>
#include "Subject.h"
using namespace std;

class RecordBook {
private:
    string recordNumber;
    Subject subjects[10];
    int subjectCount = 0;

public:
    RecordBook(string num) : recordNumber(num) {}

    void addSubject(const Subject& s) {
        if (subjectCount < 10) {
            subjects[subjectCount++] = s;
        }
    }

    int getSubjectCount() const { return subjectCount; }
    Subject getSubject(int index) const { return subjects[index]; }

    friend ostream& operator<<(ostream& out, const RecordBook& rb);
    friend istream& operator>>(istream& in, RecordBook& rb);
};

#endif
