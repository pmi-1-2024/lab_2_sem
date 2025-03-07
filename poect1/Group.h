#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include "Student.h"
using namespace std;

class Group {
private:
    string name;
    int studentCount;
    Student* students;

    void copyFrom(const Group& other);  
    void clear();  

public:
    Group(string name = "", int studentCount = 0);
    Group(const Group& other);  
    Group& operator=(const Group& other);  
    ~Group();

    void addStudent(const Student& student);
    Student& operator[](int index); 
    Student operator[](const string& surname) const; 

    string getName() const { return name; }  
    int getStudentCount() const { return studentCount; }

    friend ostream& operator<<(ostream& os, const Group& group);
    friend istream& operator>>(istream& is, Group& group);
};

#endif

