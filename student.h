#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Address.h"
#include "RecordBook.h"

using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    Address address;
    string groupName;
    RecordBook recordBook;

public:
    Student();
    Student(const string& firstName, const string& lastName, const Address& address, const string& groupName, const RecordBook& recordBook);

    string getFirstName() const;
    string getLastName() const;
    string getGroupName() const;
    Address getAddress() const;
    RecordBook getRecordBook() const;

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};

#endif
