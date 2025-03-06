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
   
    string getName() const;
    Address getAddress() const;
    string getGroup() const;
    RecordBook getRecordBook() const;

	void display() const;
    bool matchesCriteria(string searchValue, int searchType) const;

    friend istream& operator>>(istream& is, Student& student);
    friend ostream& operator<<(ostream& os, const Student& student);
};
#endif
