#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student_List.h"
#include "Student.h"
#include <string>
using namespace std;

class Student_Manager {
    Student_List studentList;
public:
    void add(const Student& student);
    void remove(const Student& student);
    Student* findName(const string& name);
    void replace(const string& name, const Student& newStudentData);
    void print() const;
};

#endif