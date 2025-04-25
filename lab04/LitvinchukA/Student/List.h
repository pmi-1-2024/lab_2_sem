#ifndef LIST_H
#define LIST_H

#include "Link.h"
#include <iostream>
using namespace std;

class List {
protected:
    Link* head;
public:
    List();
    virtual ~List();
    void push(Link* link);
    Link* top() const;
    void remove(Link* link);
    bool empty() const;
    Link* find(const string& name) const;
    void insert(Link* link, Link* position);
};

#endif