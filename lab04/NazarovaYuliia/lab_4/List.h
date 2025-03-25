#pragma once
#include "Student.h"
#include "Link.h"

class List {
protected:
    Link* head;
public:
    List();
    virtual ~List();
    virtual void add(Link* newLink) = 0;
    virtual void display() = 0;
};