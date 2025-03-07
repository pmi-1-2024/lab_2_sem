#ifndef RECORDBOOK_H
#define RECORDBOOK_H
#include <iostream>
#include <vector>
#include "Subject.h"
using namespace std;

class RecordBook {
public:
    string recordNumber;
    vector<Subject> subjects;

    RecordBook(string num) : recordNumber(num) {}
    void addSubject(Subject s);
    void display() const;
};
#endif
