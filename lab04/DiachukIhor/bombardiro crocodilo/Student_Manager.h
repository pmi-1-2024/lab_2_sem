#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Students_List.h"

class Student_Manager {
    Students_List list;

public:
    void addStudent(const Student& student);
    void removeStudent(const Student& student);
    void findStudent(const Student& student) const;
    void updateStudent(const Student& oldStudent, const Student& updatedStudent);
    void displayAll() const;
};

#endif 