#include "RecordBook.h"

RecordBook::RecordBook() : number(""), subjectCount(0), subjects(nullptr) {}

RecordBook::RecordBook(string num, int count) : number(num), subjectCount(count) {
    subjects = new Subject[count];
}

RecordBook::RecordBook(const RecordBook& other) {
    number = other.number;
    subjectCount = other.subjectCount;
    subjects = new Subject[subjectCount];
    for (int i = 0; i < subjectCount; i++) {
        subjects[i] = other.subjects[i];
    }
}

RecordBook& RecordBook::operator=(const RecordBook& other) {
    if (this == &other) return *this;

    delete[] subjects;

    number = other.number;
    subjectCount = other.subjectCount;
    subjects = new Subject[subjectCount];
    for (int i = 0; i < subjectCount; i++) {
        subjects[i] = other.subjects[i];
    }

    return *this;
}

RecordBook::~RecordBook() {
    delete[] subjects;
}

string RecordBook::GetNumber() const {
    return number;
}

istream& operator>>(istream& in, RecordBook& rb) {
    cout << "Enter record book number: ";
    in >> rb.number;
    cout << "Enter number of subjects: ";
    in >> rb.subjectCount;
    rb.subjects = new Subject[rb.subjectCount];

    for (int i = 0; i < rb.subjectCount; i++) {
        cout << "Enter subject " << i + 1 << " details:\n";
        in >> rb.subjects[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const RecordBook& rb) {
    out << "\nNumber: " << rb.number;
    out << "\nCount of subjects: " << rb.subjectCount;
    out << "\nSubjects: ";
    for (int i = 0; i < rb.subjectCount; i++) {
        out << rb.subjects[i] << endl;
    }
    return out;
}

Subject& RecordBook::operator[](int index) {
    if (index >= 0 && index < subjectCount) {
        return subjects[index];
    }
    else {
        throw out_of_range("Index out of range");
    }
}
