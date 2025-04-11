#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H
#include "List.h"
#include <iostream>
#include <string>

using namespace std;

class Student_Manager {
private:
    List studentsList;   
    

public:


    void pushStudent(const Student& student);

    void displayAllStudents() const;

    void popStudentByName(const string& name);
   
    bool isEmpty() const;

    
    
    

};


#endif
