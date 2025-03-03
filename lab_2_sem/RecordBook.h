#ifndef RECORDBOOK_H
#define RECORDBOOK_H
#include "Subject.h"
using namespace std;

class RecordBook {
private:
    string recordNumber;
    Subject* subjects;
    int subjectCount;
public:
    RecordBook() : recordNumber(""), subjects(nullptr), subjectCount(0) {}
    RecordBook(string recordNumber, Subject* subjects, int subjectCount)
        : recordNumber(recordNumber), subjects(subjects), subjectCount(subjectCount) {}

    ~RecordBook() { delete[] subjects; }

    void addSubject(Subject subject) {
        Subject* newSubjects = new Subject[subjectCount + 1];
        for (int i = 0; i < subjectCount; i++) newSubjects[i] = subjects[i];
        newSubjects[subjectCount] = subject;
        delete[] subjects;
        subjects = newSubjects;
        subjectCount++;
    }

    string getRecordNumber() const { return recordNumber; }
    int getSubjectCount() const { return subjectCount; }
    Subject* getSubjects() const { return subjects; }

    bool hasSubject(string subjectName) const {
        for (int i = 0; i < subjectCount; i++)
            if (subjects[i].getName() == subjectName) return true;
        return false;
    }

    bool hasSemester(string semester) const {
        for (int i = 0; i < subjectCount; i++)
            if (subjects[i].getSemester() == semester) return true;
        return false;
    }

    friend istream& operator>>(istream& is, RecordBook& recordBook) {
        is >> recordBook.recordNumber;
        string subjectName, semester;
        int grade;
        while (is >> subjectName) {
            if (subjectName == "END") break;
            is >> semester >> grade;
            recordBook.addSubject(Subject(subjectName, semester, grade));
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const RecordBook& recordBook) {
        os << recordBook.recordNumber << endl;
        for (int i = 0; i < recordBook.subjectCount; i++) {
            os << recordBook.subjects[i] << endl;
        }
        return os;
    }
};

#endif