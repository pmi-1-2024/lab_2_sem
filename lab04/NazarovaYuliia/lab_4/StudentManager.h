#pragma once
#include "StudentsList.h"

class Student_Manager {
private:
    Students_List students;
public:
    void addStudent(string fName, string lName, string grp);
    void removeStudent(string fName, string lName);
    void findStudent(const string& fName = "", const string& lName = "", const string& grp = "");
    void displayAll();
    void insertAfter(const Student& newStudent, const string& afterFName, const string& afterLName);
    Student getTopStudent() const;
};