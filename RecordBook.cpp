#include "RecordBook.h"

RecordBook::RecordBook() : number(0), subjectCount(0), subjects(nullptr) {}

RecordBook::RecordBook(int number, int subjectCount) : number(number), subjectCount(subjectCount) {
    subjects = new Subject[subjectCount];
}

RecordBook::~RecordBook() {
    delete[] subjects;
}

int RecordBook::getNumber() const {
    return number;
}

bool RecordBook::hasSubject(const string& subjectName) const {
    for (int i = 0; i < subjectCount; i++) {
        if (subjects[i].getName() == subjectName) return true;
    }
    return false;
}

bool RecordBook::hasSemester(int semester) const {
    for (int i = 0; i < subjectCount; i++) {
        if (subjects[i].getSemester() == semester) return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const RecordBook& recordBook) {
    os << "Record Book Number: " << recordBook.number << "\nSubjects:\n";
    for (int i = 0; i < recordBook.subjectCount; ++i) {
        os << recordBook.subjects[i] << "\n";
    }
    return os;
}

istream& operator>>(istream& is, RecordBook& recordBook) {
    is >> recordBook.number >> recordBook.subjectCount;
    recordBook.subjects = new Subject[recordBook.subjectCount];
    for (int i = 0; i < recordBook.subjectCount; ++i) {
        is >> recordBook.subjects[i];
    }
    return is;
}
