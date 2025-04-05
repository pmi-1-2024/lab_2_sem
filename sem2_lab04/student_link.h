#pragma once

#include "link.h"
#include "student.h"

struct Student_Link : public Link<Student> {
    Student_Link(const Student& student) : Link<Student>(student) {}
};


