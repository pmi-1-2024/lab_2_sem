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

    void display() const;

    Student* findByName(const string& name);

    void popByName(const string& name);

    void replaceStudent(const string& name, const Student& newStudent);
    bool isEmpty() const;
};

#endif
