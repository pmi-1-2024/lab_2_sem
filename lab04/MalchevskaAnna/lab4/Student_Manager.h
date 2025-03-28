#pragma once
#include "Students_List.h"
using namespace std;

class Student_Manager {
private:
    Students_List studentsList;
public:
    void addStudent(const Student& s);
    void removeStudent(const string& name);
    void findStudentByName(const string& name) const;
    void findStudentByGroup(const string& group) const;
    void findStudentByAddress(const string& address) const;
    void updateStudent(const string& name, const Student& newData);
    void printAllStudents() const;
};
