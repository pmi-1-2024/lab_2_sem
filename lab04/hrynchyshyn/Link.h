#pragma once

#include "Student.h"

struct Link {
    Link* next;
    virtual ~Link() {}
protected:
    Link() : next(nullptr) {}
};

struct Student_Link : Link {
    Student student;

   Student_Link(const Student& s) : student(s) {}
};




