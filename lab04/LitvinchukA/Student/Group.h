#ifndef GROUP_H
#define GROUP_H

#include "Student.h"
#include <string>
using namespace std;

class Group {
    string name;
    Student* students;
    unsigned studentsCount;

public:
    Group() : name(""), students(nullptr), studentsCount(0) {}
    Group(string name);
    Group(const Group& other);
    Group& operator=(const Group& other);
    ~Group();
    void add(const Student& student);

    string getName() const;
    unsigned getStudentsCount() const;
    Student* getStudents() const;

    friend istream& operator>>(istream& is, Group& group);
    friend ostream& operator<<(ostream& os, const Group& group);
};

#endif