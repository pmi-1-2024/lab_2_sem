#include "RecordBook.h"

RecordBook::RecordBook() : number(0), subjects(nullptr), subjectCount(0) {}

RecordBook::RecordBook(int number, Subject* subjects, int subjectCount)
    : number(number), subjects(subjects), subjectCount(subjectCount) {}

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

int RecordBook::getNumber() const {
    return number;
}

void RecordBook::addSubject(const Subject& subject) {
    Subject* newSubjects = new Subject[subjectCount + 1];
    for (int i = 0; i < subjectCount; i++) {
        newSubjects[i] = subjects[i];
    }
    newSubjects[subjectCount] = subject;
    delete[] subjects;
    subjects = newSubjects;
    subjectCount++;
}

Subject& RecordBook::operator[](int index) { 
    if (index < 0 || index >= subjectCount) {
        throw out_of_range("Index out of range");
    }
    return subjects[index];
}



ostream& operator<<(ostream& os, const RecordBook& recordBook) {
    os << "Record Book Number: " << recordBook.number << "\nSubjects:\n";
    for (int i = 0; i < recordBook.subjectCount; i++) {
        os << recordBook.subjects[i] << endl;
    }
    return os;
}

istream& operator>>(istream& is, RecordBook& recordBook) {
    cout << "Enter record book number: ";
    is >> recordBook.number;

    cout << "Enter number of subjects: ";
    is >> recordBook.subjectCount;
    recordBook.subjects = new Subject[recordBook.subjectCount];

    for (int i = 0; i < recordBook.subjectCount; i++) {
        is >> recordBook.subjects[i];
    }
    return is;
}