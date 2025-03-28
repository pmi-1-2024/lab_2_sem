#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H
#include "List.h"
using namespace std;

class Student_Manager {
private:
    List studentsList;

public:
    void pushStudent(const Student& student);

    void displayAllStudents() const;

    Student* searchStudentByName(const string& name);

    void popStudentByName(const string& name);

    void replaceStudentData(const string& name, const Student& newStudent);

    bool isEmpty() const;
};


#endif
