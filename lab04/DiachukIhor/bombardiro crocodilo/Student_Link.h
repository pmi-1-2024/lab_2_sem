#ifndef STUDENT_LINK_H
#define STUDENT_LINK_H
#include "Link.h"
#include "Student.h"

struct Student_Link : Link {
    Student data;
    Student_Link(const Student& student) : data(student) {}
};

#endif 
