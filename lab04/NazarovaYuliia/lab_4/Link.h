#pragma once
#include "Student.h"

struct Link {
    Link* next;
    Link();
};

struct Student_Link : public Link {
    Student student;
    Student_Link(Student s);
};