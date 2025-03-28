#pragma once
#include <iostream>
#include "Subject.h"
using namespace std;

class Zalikovka {
private:
    string zalikovkaNumber;
    Subject* subjects;
    int subjectCount;

    void deepCopy(const Zalikovka& other) {
        zalikovkaNumber = other.zalikovkaNumber;
        subjectCount = other.subjectCount;
        subjects = new Subject[subjectCount];
        for (int i = 0; i < subjectCount; i++) {
            subjects[i] = other.subjects[i];
        }
    }
public:
    Zalikovka();

    Zalikovka(string zalikovkaNumber, Subject* subject, int subjectCount);
    Zalikovka(const Zalikovka& zalikovka);
    Zalikovka& operator=(const Zalikovka& zalikovka);
    Subject& operator[](int index);
    ~Zalikovka();

    void addSubject(Subject subject);
    string getZalikovkaNumber() const;
    int getSubjectCount() const;
    Subject* getSubjects() const;

    bool hasSubject(string subjectName) const;
    bool hasSemester(string semester) const;

    friend ostream& operator<<(ostream& os, const Zalikovka& zalikovka);
    friend istream& operator>>(istream& is, Zalikovka& zalikovka);
};
