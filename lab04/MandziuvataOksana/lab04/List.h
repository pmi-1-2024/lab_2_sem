#pragma once
#include "link.h"

class List {
protected:
    Link* head;
public:
    List();
    bool empty() const;
    Link* front() const;
    void push_front(Link* new_elem);
    void pop_front();
    virtual ~List();
};
