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
public:
    Group(string name = "", int studentCount = 0);
    ~Group();
    void addStudent(const Student& student);
    friend ostream& operator<<(ostream& os, const Group& group);
    friend istream& operator>>(istream& is, Group& group);
};

#endif
