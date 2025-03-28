#ifndef LINKS_H
#define LINKS_H
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

struct Link {
    Link* next;
    virtual ~Link() {}
protected:
    Link() :next(0) {}
};

struct Student_link : Link {
    Student data;
    Student_link(const Student& d) : data(d) {}
};
#endif
