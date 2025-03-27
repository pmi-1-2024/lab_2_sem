#pragma once

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name, group, recordNumber;

public:
    Student();
    Student(string name, string group, string recordNumber);

    friend istream& operator>>(istream& in, Student& student);
    friend ostream& operator<<(ostream& out, const Student& student);

    const string& getName() const;
    const string& getGroup() const;
    const string& getRecordNumber() const;

    void setName(const string& newName);
    void setGroup(const string& newGroup);
    void setRecordNumber(const string& newRecordNumber);
};


