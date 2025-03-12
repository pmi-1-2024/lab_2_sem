#include "Zalikovka.h"
#include <iostream>
using namespace std;

Zalikovka::Zalikovka() : zalikovkaNumber(""), subjectCount(0), subjects(nullptr) {}

Zalikovka::Zalikovka(string zalikovkaNumber, int subjectCount, Subject* subjects)
    : zalikovkaNumber(zalikovkaNumber), subjectCount(subjectCount) {
    this->subjects = new Subject[subjectCount];
    for (int i = 0; i < subjectCount; i++) {
        this->subjects[i] = subjects[i];
    }
}


Zalikovka::Zalikovka(const Zalikovka& zalikovka) {
    zalikovkaNumber = zalikovka.zalikovkaNumber;
    subjectCount = zalikovka.subjectCount;
    subjects = new Subject[subjectCount];
    for (int i = 0; i < subjectCount; i++) {
        subjects[i] = zalikovka.subjects[i];
    }
}

Zalikovka& Zalikovka::operator=(const Zalikovka& zalikovka) {
    if (this == &zalikovka) {
        return *this;
    }

    delete[] subjects; 

    subjectCount = zalikovka.subjectCount;
    subjects = new Subject[subjectCount];

    for (int i = 0; i < subjectCount; i++) {
        subjects[i] = zalikovka.subjects[i];
    }

    zalikovkaNumber = zalikovka.zalikovkaNumber;
    return *this;

}

Zalikovka::~Zalikovka() {
    if (subjects) {
        delete[] subjects;
    }
}


string Zalikovka::getZalikovkaNumber() const { return zalikovkaNumber; }
int Zalikovka::getSubjectCount() const { return subjectCount; }
Subject* Zalikovka::getSubjects() const { return subjects; }



void Zalikovka::addSubject(Subject subject) {
    Subject* newSubjects = new Subject[subjectCount + 1];

    for (int i = 0; i < subjectCount; i++) {
        newSubjects[i] = subjects[i];
    }
    newSubjects[subjectCount] = subject;

    delete[] subjects;

    subjects = newSubjects;
    subjectCount++;
}

bool Zalikovka::hasSubject(string subjectName) const {
    for (int i = 0; i < subjectCount; i++)
        if (subjects[i].getName() == subjectName) return true;
    return false;
}

bool Zalikovka::hasSemester(string semester) const {
    for (int i = 0; i < subjectCount; i++)
        if (subjects[i].getSemester() == semester) return true;
    return false;
}

Subject& Zalikovka::operator[](int index) {
    if (index < 0 || index >= subjectCount) {
        throw out_of_range("Invalid index");
    }
    return subjects[index];
}

ostream& operator<<(ostream& os, const Zalikovka& zalikovka) {
    os << "Номер залікової книжки: " << zalikovka.zalikovkaNumber << "\n";
    for (int i = 0; i < zalikovka.subjectCount; i++) {
        os << zalikovka.subjects[i] << endl;
    }
    os << "END" << endl;
    return os;
}

istream& operator>>(istream& is, Zalikovka& zalikovka) {
    is >> zalikovka.zalikovkaNumber;
    string subjectName, semester;
    int grade;
    while (is >> subjectName) {
        if (subjectName == "END") break;
        is >> semester >> grade;
        zalikovka.addSubject(Subject(subjectName, semester, grade));
    }
    return is;
}