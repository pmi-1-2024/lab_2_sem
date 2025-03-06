#pragma once
#include <iostream>
#include <string>
#include "Subject.h"

using namespace std;

class RecordBook {
private:
    string recordNumber;
    Subject* subjects;
    int subjectCount;

public:
    RecordBook();
    ~RecordBook();
    RecordBook(const RecordBook& other); 
    RecordBook& operator=(const RecordBook& other);
    friend istream& operator>>(istream& in, RecordBook& recordBook);
    friend ostream& operator<<(ostream& out, const RecordBook& recordBook);
    const string& getRecordNumber() const;
    const Subject* getSubjects() const;
    int getSubjectCount() const;
};

