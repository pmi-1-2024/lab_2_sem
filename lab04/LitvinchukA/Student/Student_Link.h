#ifndef STUDENT_LINK_H
#define STUDENT_LINK_H

#include "Link.h"
#include "Student.h"

struct Student_Link : public Link {
    Student student;
    Student_Link(const Student& student) : student(student) {}
};

#endif