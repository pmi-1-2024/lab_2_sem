#pragma once

#include "Link.h"

class List {
    List(const List&) = delete;
    List& operator=(const List&) = delete;

protected:
    Link* head;
    void push(Link* node);
    Link* top() const;

public:
    List();
    virtual ~List();
    Link* remove(Link* node = 0);
    bool empty() const;
};
