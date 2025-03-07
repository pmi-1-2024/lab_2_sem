#include "RecordBook.h"

RecordBook::RecordBook() : number(""), subjectCount(0), subjects(nullptr) {}

RecordBook::RecordBook(string num, int count) : number(num), subjectCount(count) {
    subjects = new Subject[count];
}

RecordBook::~RecordBook() {
    delete[] subjects;
}

string RecordBook::GetNumber() const
{
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

ostream& operator<<(ostream& out, const RecordBook& rb)
{
    out << "\nNumber: " << rb.number;
    out << "\nCount of subject: " << rb.subjectCount;
    out << "\nSubjects: ";
    for (int i = 0; i < rb.subjectCount; i++) {
        cout << rb.subjects[i];
    }
    return out;
}
