#ifndef STUDENT_LINK_H
#define STUDENT_LINK_H

#include <string>
#include "Link.h"
using namespace std;

struct Student {
    string name;
    int age;
    string group;

    Student(string n, int a, string g);
    void display() const;
};

struct Student_Link : public Link {
    Student student;  
    Student_Link(const Student& s);
};

#endif