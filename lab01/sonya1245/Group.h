#pragma once
#include <iostream>
#include <string>
#include "Student.h" 

using namespace std;

class Group {
private:
    string name;
    Student* students;
    int studentCount;

public:
    Group();
    Group(const string& name);
    Group(const Group& other);
    Group& operator=(const Group& other);
    ~Group();
    void addStudent(const Student& student);
    void searchByName(const string& name) const;
    void searchByGroupName(const string& groupName) const;
    void searchByRecordNumber(const string& recordNumber) const;
    void searchByAddress(const Address& address) const;
    void searchByCity(const string& city) const;
    void searchBySubjectName(const string& subjectName) const;
    void searchBySemester(int semester) const;
    const Student& operator[](int index) const;
    friend istream& operator>>(istream& in, Group& group);
    friend ostream& operator<<(ostream& out, const Group& group);
};

