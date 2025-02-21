#ifndef STUDENT_H
#define STUDENT_H
#include "Address.h"
#include "RecordBook.h"
#include <iostream>
using namespace std;

class Student {
private:
    string name, group;
    Address address;
    RecordBook recordBook;
public:
    Student();
    Student(string name, Address address, string group, RecordBook recordBook);
    void display() const;
    string getName() const;
    Address getAddress() const;
    string getGroup() const;
    RecordBook getRecordBook() const;
    bool matchesCriteria(string searchValue, int searchType) const;
};
#endif
