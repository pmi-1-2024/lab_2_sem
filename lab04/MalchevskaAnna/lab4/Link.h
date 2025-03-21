#pragma once
#include "Student.h"
using namespace std;

struct Link {
    Link* next;
    virtual ~Link() {}
protected:
    Link() : next(nullptr) {}
};
struct Student_Link : Link {
    Student data;
    Student_Link(const Student& s);
};
