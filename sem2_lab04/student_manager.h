#pragma once

#include "students_list.h"
#include "student.h"
#include <iostream>
#include <fstream>

class Student_Manager {
private:
    Students_List students;

public:
    void addStudent(const Student& student);
    void removeStudent(const string& firstName, const string& lastName);
    void replaceStudent(const string& firstName, const string& lastName, const Student& newStudent);
    void findStudent(const string& firstName, const string& lastName);
    void printAllStudents() const;
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename) const;
};


