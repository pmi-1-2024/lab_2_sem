#include "RecordBook.h"
#include <iostream>

RecordBook::RecordBook(string number, int subjectCount)
    : number(number), subjectCount(subjectCount) {
    subjects = new Subject[subjectCount];
}

RecordBook::~RecordBook() {
    delete[] subjects;
}
void RecordBook::input() {
    cout << "Enter record book number: ";
    cin >> number;
    cout << "Enter number of subjects: ";
    cin >> subjectCount;

    delete[] subjects;
    subjects = new Subject[subjectCount];

    for (int i = 0; i < subjectCount; ++i) {
        cout << "Enter details for subject " << i + 1 << ":\n";
        subjects[i].input();
    }
}

void RecordBook::output() const {
    cout << "Record Book Number: " << number << "\nSubjects:\n";
    for (int i = 0; i < subjectCount; ++i) {
        subjects[i].output();
    }
}
