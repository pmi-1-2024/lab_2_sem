#pragma once
#include <iostream>
#include <fstream>
#include "Student.h"
#include "Functions.h"
using namespace std;

class Group {
private:
    string name;
    int studentCount;
    Student* students;
public:
    Group();
    Group(string name, int studentCount, Student* student);
    Group(const Group& group);
    Group& operator=(const Group& group);
    ~Group();
    Student& operator[](int index);

    string getName() const;
    void saveToFile(const string& filename);
    void addStudent(const Student& student);
    int getStudentCount() const;
    Student* getStudents() const;
    void addStudents(const Student* students, int count);
    void removeStudent(string studentName);
    void searchByGroup(const string& groupName) const;
    void searchByAddress(const Address& address) const;
    void searchByZalikovkaNumber(const string& zalikovka) const;
    void searchBySubject(const string& subject) const;

    friend ostream& operator<<(ostream& os, const Group& group);
    friend istream& operator>>(istream& is, Group& group);
};
