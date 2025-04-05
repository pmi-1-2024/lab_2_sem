#pragma once

#include "list.h"
#include "student_link.h"

class Students_List : public List<Student> {
public:
    void addStudent(const Student& student);
    void removeStudent(const string& firstName, const string& lastName);
    Student* findStudent(const string& firstName, const string& lastName);
    void replaceStudent(const string& firstName, const string& lastName, const Student& newStudent);
    void printAllStudents(ostream& os) const;
};


