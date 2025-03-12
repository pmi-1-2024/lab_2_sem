#pragma once
#include <iostream>
#include "Subject.h"
using namespace std;

class Zalikovka {
private:
    string zalikovkaNumber;
    int subjectCount;
    Subject* subjects;
public:
    Zalikovka();

    Zalikovka(string zalikovkaNumber, int subjectCount, Subject* subject);
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
