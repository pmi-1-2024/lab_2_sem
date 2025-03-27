#pragma once

#include "Student_List.h"

class Student_Manager {
private:
    Students_List students;
public:
    void addStudent();
    void removeStudent();
    void findStudent();
    void updateStudent();
    void displayAllStudents();
    void menu();
};

