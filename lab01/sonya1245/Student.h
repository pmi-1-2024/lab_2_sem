#pragma once
#include <iostream>
#include <string>
#include "Address.h"
#include "RecordBook.h"

using namespace std;

class Student {
private:
    string name;
    Address address;
    string group;
    RecordBook recordBook;

public:
    Student();
    friend istream& operator>>(istream& in, Student& student);
    friend ostream& operator<<(ostream& out, const Student& student);
    const string& getName() const;
    const string& getGroup() const;
    const string& getRecordNumber() const;
    const Address& getAddress() const;
    const RecordBook& getRecordBook() const;
};

