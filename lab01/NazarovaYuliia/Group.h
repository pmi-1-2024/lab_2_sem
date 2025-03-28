#pragma once
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

class Group {
private:
	string name;
	int studentCount;
	Student* students;

public:
    Group(const string& groupName = "");
    Group(const Group& other);
    Group& operator=(const Group& other);
    ~Group();

    string getName() const;
    int getStudentCount() const;
    const Student* getStudents() const;

    void addStudent(const Student& student);
    void removeStudent(const string& studentName);

    Student& operator[](int index);
    Student& operator[](const string& studentName);

    friend istream& operator>>(istream& is, Group& group);
    friend ostream& operator<<(ostream& os, const Group& group);
};
