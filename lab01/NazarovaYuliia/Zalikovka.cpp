#include "Zalikovka.h"
#include <iostream>
using namespace std;

Zalikovka::Zalikovka(): number(""), subjectCount(0), subjects(nullptr) {}
Zalikovka::Zalikovka(const Zalikovka& other) {
    number = other.number;
    subjectCount = other.subjectCount;
    subjects = (subjectCount > 0) ? new Subject[subjectCount] : nullptr;
        for (int i = 0; i < subjectCount; ++i) {
            subjects[i] = other.subjects[i];
        }
    }
}

Zalikovka& Zalikovka::operator=(const Zalikovka& other) {
    if (this == &other) {
        delete[] subjects;
        number = other.number;
        subjectCount = other.subjectCount;
        subjects = (subjectCount > 0) ? new Subject[subjectCount] : nullptr;
        for (int i = 0; i < subjectCount; ++i) {
            subjects[i] = other.subjects[i];
        }
    }
    return *this;
}

Zalikovka::~Zalikovka() {
	delete[] subjects;
}

void Zalikovka::setNumber(const string& number) {
    this->number = number;
}

void Zalikovka::setSubjects(const Subject* subjects, int count) {
    delete[] this->subjects;
    subjectCount = count;
    this->subjects = (count > 0) ? new Subject[count] : nullptr;
    for (int i = 0; i < count; ++i) {
            this->subjects[i] = subjects[i];
        
    }
}

string Zalikovka::getNumber() const {
    return number;
}

Subject* Zalikovka::getSubjects() const {
    return subjects;
}

int Zalikovka::getSubjectCount() const {
    return subjectCount;
}

Subject& Zalikovka::operator[](int index) {
    if (index < 0 || index >= subjectCount) {
        cerr << "Index out of range!" << endl;
        exit(EXIT_FAILURE);
    }
    return subjects[index];
}

ostream& operator<<(ostream& os, const Zalikovka& z) {
    os << "Zalikovka number: " << z.number << endl;
    os << "Subjects count: " << z.subjectCount << endl;
    for (int i = 0; i < z.subjectCount; ++i) {
        os << "Subject " << i + 1 << ": " << z.subjects[i] << endl;
    }
    return os;
}

istream& operator>>(istream& is, Zalikovka& z) {
    cout << "Enter zalikovka number: ";
    is.ignore();
    getline(is, z.number);

    cout << "Enter number of subjects: ";
    is >> z.subjectCount;
    is.ignore();

    delete[] z.subjects;
    z.subjects = (z.subjectCount > 0) ? new Subject[z.subjectCount] : nullptr;

    for (int i = 0; i < z.subjectCount; ++i) {
        cout << "Enter details for subject " << i + 1 << ": ";
        is >> z.subjects[i];
    }

    return is;
}