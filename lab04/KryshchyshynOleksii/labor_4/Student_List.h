#ifndef STUDENTS_LIST_H
#define STUDENTS_LIST_H

#include "List.h"
#include "Student_Link.h"
using namespace std;

class Students_List : public List {
public:
    /*Students_List();
    ~Students_List();*/

    void push(const Student& student);
    void display() const;
    void pop(const string& name);

   
};

#endif
