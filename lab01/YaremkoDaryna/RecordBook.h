#ifndef RECORDBOOK_H
#define RECORDBOOK_H
#include "Subject.h"
#include <iostream>
using namespace std;

class RecordBook {
private:
    string recordNumber;
    Subject subjects[10];
    int subjectCount;
public:
    RecordBook(string recordNumber = "")
        : recordNumber(recordNumber), subjectCount(0) {
    }

    void addSubject(Subject subject) {
        if (subjectCount < 10) subjects[subjectCount++] = subject;
    }

    void display() const {
        cout << "Номер заліковки: " << recordNumber << endl;
        for (int i = 0; i < subjectCount; i++) subjects[i].display();
    }

    string getRecordNumber() const { return recordNumber; }

    bool hasSubject(string subjectName) const {
        for (int i = 0; i < subjectCount; i++)
            if (subjects[i].getName() == subjectName) return true;
        return false;
    }

    bool hasSemester(int semester) const {
        for (int i = 0; i < subjectCount; i++)
            if (subjects[i].getSemester() == semester) return true;
        return false;
    }
};
#endif
