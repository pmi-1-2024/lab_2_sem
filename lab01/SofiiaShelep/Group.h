#pragma once
#include "Student.h"
#include <iostream>

using namespace std;

class Group
{
private:
    string groupName;
    int studentCount;
    Student* students;

public:
    Group() : groupName("Default"), studentCount(0), students(nullptr) {}
    Group(string name, int maxStudents);

    Group(const Group& other) : groupName(other.groupName), studentCount(other.studentCount)
    {
        if (studentCount > 0)
        {
            students = new Student[studentCount];
            for (int i = 0; i < studentCount; i++)
            {
                students[i] = other.students[i];
            }
        }
        else
        {
            students = nullptr;
        }
    }

    Group& operator=(const Group& other)
    {
        if (this != &other)
        {
            delete[] students;
            groupName = other.groupName;
            studentCount = other.studentCount;

            if (studentCount > 0)
            {
                students = new Student[studentCount];
                for (int i = 0; i < studentCount; i++)
                {
                    students[i] = other.students[i];
                }
            }
            else
            {
                students = nullptr;
            }
        }
        return *this;
    }

    ~Group()
    {
        delete[] students;
    }

    void addStudent(const Student& student);
    void removeStudent(const string& studentName);
    void showGroup() const;

    string getGroupName() const;
    int getStudentCount() const;
    Student& operator[](int index);

    friend ostream& operator<<(ostream& os, const Group& group)
    {
        os << "Group Name: " << group.groupName << "\n";
        os << "Student Count: " << group.studentCount << "\n";

        for (int i = 0; i < group.studentCount; i++)
        {
            os << group.students[i] << "\n";
        }
        return os;
    }

    friend istream& operator>>(istream& is, Group& group)
    {
        is >> group.groupName;
        is >> group.studentCount;

        delete[] group.students;
        group.students = new Student[group.studentCount];

        for (int i = 0; i < group.studentCount; i++)
        {
            is >> group.students[i];
        }
        return is;
    }
};