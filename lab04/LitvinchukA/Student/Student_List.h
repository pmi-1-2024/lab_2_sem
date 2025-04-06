#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include "List.h"
#include "Student_Link.h"

class Student_List : public List {
public:
    void push(const Student& student);
    void remove(const Student& student);
    Student* find(const string& name) const;
    void insert(const Student& student, const string& positionName);
    void print() const;
};

#endif