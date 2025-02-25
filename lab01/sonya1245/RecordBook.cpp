#include "RecordBook.h"

RecordBook::RecordBook() : recordNumber(""), subjects(nullptr), subjectCount(0) {}

RecordBook::~RecordBook() {
    delete[] subjects; // Звільняємо пам'ять
}

RecordBook::RecordBook(const RecordBook& other) {
    recordNumber = other.recordNumber;
    subjectCount = other.subjectCount;
    subjects = new Subject[subjectCount];
    for (int i = 0; i < subjectCount; i++) {
        subjects[i] = other.subjects[i];
    }
}

RecordBook& RecordBook::operator=(const RecordBook& other) {
    if (this != &other) {
        delete[] subjects; // Звільняємо попередню пам'ять
        recordNumber = other.recordNumber;
        subjectCount = other.subjectCount;
        subjects = new Subject[subjectCount];
        for (int i = 0; i < subjectCount; i++) {
            subjects[i] = other.subjects[i];
        }
    }
    return *this;
}

istream& operator>>(istream& in, RecordBook& recordBook) {
    cout << "Enter record book number: ";
    in >> recordBook.recordNumber;
    cout << "Enter the number of subjects: ";
    in >> recordBook.subjectCount;
    recordBook.subjects = new Subject[recordBook.subjectCount];
    for (int i = 0; i < recordBook.subjectCount; i++) {
        in >> recordBook.subjects[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const RecordBook& recordBook) {
    out << "Record Book Number: " << recordBook.recordNumber << "\n";
    for (int i = 0; i < recordBook.subjectCount; i++) {
        out << recordBook.subjects[i] << "\n";
    }
    return out;
}

const string& RecordBook::getRecordNumber() const {
    return recordNumber;
}

const Subject* RecordBook::getSubjects() const {
    return subjects;
}

int RecordBook::getSubjectCount() const {
    return subjectCount;
}