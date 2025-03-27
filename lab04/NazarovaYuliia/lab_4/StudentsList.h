#pragma once

#include "List.h"
#include "Student.h"
#include "Link.h"

class Students_List : public List {
public:
    Students_List() { head = nullptr; }
    void display() override;
    void remove(string fName, string lName);
    void push(Student s);  
    Student top() const;  
    Student_Link* find(Student s);
    void insert(Student s, Student_Link* after);
protected:
    void add(Link* newLink) override;
};