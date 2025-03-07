#pragma once
#include "Address.h"
#include "RecordBook.h"
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    Address address;
    string groupName;
    RecordBook recordBook;

public:
    Student();
    Student(string name, Address address, string groupName, RecordBook recordBook);

    string getName() const;
    string getGroupName() const;
    string getRecordNumber() const;
    Address getAddress() const;
    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};