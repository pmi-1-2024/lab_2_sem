#pragma once
#include <iostream>
#include <fstream>
#include "Student.h"
#include "Functions.h"
using namespace std;

class Group {
private:
    string name;
    Student* students;
    int studentCount;

    void deepCopy(const Group& other) {
        name = other.name;
        studentCount = other.studentCount;
        students = new Student[studentCount];
        for (int i = 0; i < studentCount; i++) {
            students[i] = other.students[i];
        }
    }
public:
    Group();
    Group(string name, Student* student, int studentCount);
    Group(const Group& group);
    Group& operator=(const Group& group);
    ~Group();
    Student& operator[](int index);

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
