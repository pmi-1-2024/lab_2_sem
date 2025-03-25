#pragma once
#include "StudentsList.h"

class Student_Manager {
private:
    Students_List students;
public:
    void addStudent(string fName, string lName, string grp);
    void removeStudent(string fName, string lName);
    void findStudentByName(string fName);
    void findStudentByLastName(string lName);
    void findStudentsByGroup(string grp);
    void displayAll();
};