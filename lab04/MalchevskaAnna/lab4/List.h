#pragma once
#include "Link.h"
using namespace std;

class List {
    List(const List&);
    List& operator=(const List&);
protected:
    Link* head;
    void push(Link* node);
    Link* top() const;
public:
    List();
    ~List();
    Link* remove(Link* node = nullptr);
    bool empty() const;
};
