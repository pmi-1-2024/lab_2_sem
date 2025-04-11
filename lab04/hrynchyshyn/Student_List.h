#pragma once
#include "List.h"
#include "Student.h"

class Students_List : public List {
public:
    void push(const Student& s);
    Student topStudent() const;
    Student_Link* find(const string& recordNumber);
    void insert(const Student& s, Student_Link* after);
};
