#ifndef STUDENT_H
#define STUDENT_H

#include "Address.h"
#include "RecordBook.h"
#include <iostream>

using namespace std;

class Student {
private:
    string name;
    Address address;
    string group;
    RecordBook recordBook;

public:
    Student() : name(""), address(Address("", "", "")), group(""), recordBook(RecordBook("")) {}

    Student(string n, Address a, string g, RecordBook rb)
        : name(n), address(a), group(g), recordBook(rb) {}

    const RecordBook& getRecordBook() const { return recordBook; }

    friend ostream& operator<<(ostream& out, const Student& student);
    friend istream& operator>>(istream& in, Student& student);
};

#endif
