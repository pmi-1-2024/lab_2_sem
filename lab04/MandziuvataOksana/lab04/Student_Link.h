#pragma once
#include "link.h"
#include "student.h"

class StudentLink : public Link {
public:
    Student value;
    StudentLink() : Link() {}
    StudentLink(Link* l, const Student& s) : Link(l), value(s) {}
    ~StudentLink() override = default;
};