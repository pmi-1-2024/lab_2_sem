#pragma once

#include "List.h"
#include "Student.h"
#include "Link.h"

class Students_List : public List {
public:
    Students_List() { head = nullptr; }
    void add(Link* newLink) override;
    void display() override;
    Student_Link* findByName(string fName);
    Student_Link* findByLastName(string lName);
    void findByGroup(string grp);
    void remove(string fName, string lName);
};