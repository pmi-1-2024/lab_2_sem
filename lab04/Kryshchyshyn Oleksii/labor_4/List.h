#ifndef LIST_H
#define LIST_H

#include "Student_Link.h"
using namespace std;
class List {
    List(const List&);
    List& operator = (const List&);
protected:
    Link* head;

public:

    ~List();

    List() : head(nullptr) {}

    void push(Student_Link* newLink);
    void pop(const string& name);
    void display() const;
    bool isEmpty() const;
};
#endif
