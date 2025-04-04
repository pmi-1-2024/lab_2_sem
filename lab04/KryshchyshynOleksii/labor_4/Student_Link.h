#ifndef STUDENT_LINK_H
#define STUDENT_LINK_H

#include <string>
#include "Link.h"
using namespace std;

struct Student {
    string name;
    int age;
    string group;

    
    void display() const;

    Student(string n = "", int a = 0, string g = "");

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);

};

struct Student_Link : public Link {
    Student student;
    Student_Link(const Student& s);
};

#endif
