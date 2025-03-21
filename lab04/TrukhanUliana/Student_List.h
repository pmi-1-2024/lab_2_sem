#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include "List.h"

class Student_List : public List {
public:
    void add(string n, string sn, double a);
    Student_Link* top() const;
    Student_Link* find(string n, string sn);
    void insert(string n, string sn, double a, Student_Link* after);
};

#endif // STUDENT_LIST_H
