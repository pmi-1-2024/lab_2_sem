#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include "List.h"

class Student_List : public List {
public:
    void push(const Student& student);
    Student_Link* top() const;
    Student_Link* find(const Student& student);
    void insert(const Student& student, Student_Link* after);
};

#endif // STUDENT_LIST_H
