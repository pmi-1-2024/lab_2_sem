#pragma once

#include "Student.h"

struct Link {
    Link* next;
    virtual ~Link() {}
protected:
    Link() : next(nullptr) {}
};

struct Student_Link : Link {
    Student student;
    Student_Link(const Student& s);
};

class Students_List {
private:
    Link* head;
public:
    Students_List();
    ~Students_List();
    Link* getHead() const;
    void setHead(Link* newHead);
};


