#pragma once
#include "Subject.h"
#include <iostream>
using namespace std;

class RecordBook {
private:
    int number;
    Subject* subjects;
    int subjectCount;

public:
    RecordBook();
    RecordBook(int number, Subject* subjects, int subjectCount);
    RecordBook(const RecordBook& other); 
    RecordBook& operator=(const RecordBook& other);  
    ~RecordBook();

    int getNumber() const;
    void addSubject(const Subject& subject);
    Subject& operator[](int index);
    friend ostream& operator<<(ostream& os, const RecordBook& recordBook);
    friend istream& operator>>(istream& is, RecordBook& recordBook);
};