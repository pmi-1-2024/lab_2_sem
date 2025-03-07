#pragma once
#include "Student.h"

class Group
{
private:
    string groupName;
    int studentCount;
    Student* students;

public:
    Group(){
		groupName = "Default";
		studentCount = 0;
		students = nullptr;
        }
    Group(string name, int maxStudents);
    ~Group();

    void addStudent(const Student& student);
    void removeStudent(const string& studentName);
    void showGroup() const;

    string getGroupName() const;
    int getStudentCount() const;
    Student& operator[](int index);
};