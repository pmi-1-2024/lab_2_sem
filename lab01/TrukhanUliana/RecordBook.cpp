#include "RecordBook.h"

RecordBook::RecordBook(string recordNumber)
    : recordNumber(recordNumber), subjectCount(0) {
}

void RecordBook::addSubject(Subject subject) {
    if (subjectCount < 10) subjects[subjectCount++] = subject;
}

void RecordBook::display() const {
    cout << "Record Book: " << recordNumber << endl;
    for (int i = 0; i < subjectCount; i++) subjects[i].display();
}

string RecordBook::getRecordNumber() const { return recordNumber; }

bool RecordBook::hasSubject(string subjectName) const {
    for (int i = 0; i < subjectCount; i++)
        if (subjects[i].getName() == subjectName) return true;
    return false;
}

bool RecordBook::hasSemester(string semester) const {
    for (int i = 0; i < subjectCount; i++)
        if (subjects[i].getSemester() == semester) return true;
    return false;
}
