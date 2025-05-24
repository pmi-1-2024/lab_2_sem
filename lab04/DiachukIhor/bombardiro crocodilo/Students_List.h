#ifndef STUDENTS_LIST_H
#define STUDENTS_LIST_H
#include "List.h"
#include "Student_Link.h"

class Students_List : public List {
public:
    void push(const Student& student);
    Student_Link* find(const Student& student) const;
    void insert(const Student& student, Student_Link* after);
    void printAll() const;
};

#endif 