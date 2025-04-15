#ifndef STUDENT_H
#define STUDENT_H

#include "Address.h"
#include "RecordBook.h"

class Student {
private:
    string name;
    Address address;
    string group;
    RecordBook recordBook;

public:
    Student();
    Student(string n, Address addr, string gr, RecordBook rb);

    friend istream& operator>>(istream& in, Student& s);
    friend ostream& operator<<(ostream& out, const Student& s);

    string GetName() const;
    string GetGroup() const;
    Address GetAddress() const;
    string GetRecordNumber() const;
};

#endif
