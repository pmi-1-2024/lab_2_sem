#ifndef RECORDBOOK_H
#define RECORDBOOK_H

#include "Subject.h"

class RecordBook {
private:
    string number;
    Subject* subjects;
    int subjectCount;

public:
    RecordBook();
    RecordBook(string num, int count);
    RecordBook(const RecordBook& other);
    RecordBook& operator=(const RecordBook& other);
    ~RecordBook();

    friend istream& operator>>(istream& in, RecordBook& rb);
    friend ostream& operator<<(ostream& out, const RecordBook& rb);

    string GetNumber() const;
    Subject& operator[](int index);
};

#endif

