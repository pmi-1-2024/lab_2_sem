#ifndef RECORDBOOK_H
#define RECORDBOOK_H
#include "Subject.h"
using namespace std;

class RecordBook {
private:
    string recordNumber;
    Subject subjects[10];
    int subjectCount;
public:
    RecordBook(string recordNumber);
    void addSubject(Subject subject);
    void display() const;
    string getRecordNumber() const;
    bool hasSubject(string subjectName) const;
    bool hasSemester(string semester) const;
};
#endif
