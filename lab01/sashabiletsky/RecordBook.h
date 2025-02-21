#ifndef RECORDBOOK_H
#define RECORDBOOK_H

#include <iostream>
#include <vector>
#include "Predmet.h"
using namespace std;

class RecordBook {
public:
    string recordNumber;
    vector<Predmet> subjects;

    RecordBook(string rn) : recordNumber(rn) {}
    void addSubject(Predmet subject) {
        subjects.push_back(subject);
    }
    void print() {
        cout << "Record Number: " << recordNumber << endl;
        for (auto& subject : subjects) {
            cout << "Predmet: " << subject.name << ", Semester: " << subject.semester << ", Grade: " << subject.grade << endl;
        }
    }
};

#endif 
