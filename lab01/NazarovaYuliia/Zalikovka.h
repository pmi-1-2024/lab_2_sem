#pragma once
#include "Subject.h"
#include <string>
#include <iostream>
using namespace std;

class Zalikovka {
private:
    string number;
    Subject* subjects;
    int subjectCount;

public:
    Zalikovka();
    Zalikovka(const Zalikovka& other);
    Zalikovka& operator=(const Zalikovka& other);
    ~Zalikovka();

    string getNumber() const;
    const Subject* getSubjects() const;
    int getSubjectCount() const;

    void setNumber(const string& number);
    void setSubjects(const Subject* subjects, int count);

    Subject& operator[](int index);

    friend ostream& operator<<(ostream& os, const Zalikovka& z);
    friend istream& operator>>(istream& is, Zalikovka& z);
};