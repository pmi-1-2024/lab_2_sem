#ifndef STUDENT_H
#define STUDENT_H
#include "Address.h"
#include "RecordBook.h"
using namespace std;

class Student {
public:
    string name;
    Address address;
    string group;
    RecordBook recordBook;

    Student(string n, Address a, string g, RecordBook rb);
    void display() const;
};
#endif