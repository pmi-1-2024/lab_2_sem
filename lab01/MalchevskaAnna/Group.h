#pragma once
#include <fstream> 
#include "Student.h"

class Group {
private:
    string name;
    Student* students;
    int studentCount;

public:
    Group();
    Group(string name, Student* students, int studentCount);
    Group(const Group& other);  
    Group& operator=(const Group& other);
    ~Group();

    void addStudent(const Student& student);
    void removeStudent(const string& name);
    void printStudents() const;
    void searchByName(const string& name) const;
    void searchByGroupName(const string& groupName) const;
    void searchByAddress(const Address& address) const;
    void searchByRecordNumber(const string& recordNumber) const;

    void saveToFile(const string& students) const;
    void loadFromFile(const string& students);
    Student& operator[](int index);
    friend ostream& operator<<(ostream& os, const Group& group);
    friend istream& operator>>(istream& is, Group& group);
};
