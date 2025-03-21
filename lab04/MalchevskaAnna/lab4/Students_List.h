#pragma once
#include "List.h"
#include "Student.h"

using namespace std;

class Students_List : public List {
public:
    Students_List();
    Students_List(const Students_List& other);
    Students_List& operator=(const Students_List& other);
    ~Students_List();
    void addStudent(const Student& s);
    void printAll() const;
    Student_Link* findStudentByName(const string& name) const;
    Student_Link* findStudentByGroup(const string& group) const;
    Student_Link* findStudentByAddress(const string& address) const;
    bool removeStudentByName(const string& name);
    int getSize() const;  
    Student getStudentAt(int index) const;  
};