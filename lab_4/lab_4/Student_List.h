#ifndef STUDENTS_LIST_H
#define STUDENTS_LIST_H

#include "List.h"
#include "Student_Link.h"
using namespace std;

class Students_List {
private:
    List studentList;  

public:
    Students_List();
    ~Students_List();

    void pushStudent(const Student& student);

    void displayAllStudents() const;

    Student* searchStudentByName(const string& name);

    void popStudentByName(const string& name);

    void replaceStudentData(const string& name, const Student& newStudent);
};

#endif
