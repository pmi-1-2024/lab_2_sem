#pragma once
#include "list.h"
#include "student_link.h"

class StudentList : public List {
public:
    StudentList();
    void push_front(const Student& s);
    void remove(StudentLink* s);
    void print_all() const;
    ~StudentList() override = default;
};