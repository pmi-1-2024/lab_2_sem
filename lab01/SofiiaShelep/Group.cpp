#include "Group.h"
#include <iostream>

Group::Group(string name, int maxStudents) : groupName(name), studentCount(0)
{
    students = new Student[maxStudents];
}

Group::~Group()
{
    delete[] students;
}

void Group::addStudent(const Student& student)
{
    cout << "studentCount: "<<studentCount << endl;
    students[studentCount] = student;
    studentCount++;
}

void Group::removeStudent(const string& studentName)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].getName() == studentName)
        {
            for (int j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }
            studentCount--;
            return;
        }
    }
}

void Group::showGroup() const
{
    cout << "Group: " << groupName << endl;
    for (int i = 0; i < studentCount; i++)
    {
        students[i].show();
    }
}

string Group::getGroupName() const { return groupName; }
int Group::getStudentCount() const { return studentCount; }

Student& Group::operator[](int index)
{
    return students[index];
}