#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include "Student.h"

using namespace std;

class Group {
private:
    string name;
    Student* students;
    int studentCount;

public:
    Group();
    Group(const string& name, int studentCount);
    Group(const Group& other); 
    Group& operator=(const Group& other); 
    ~Group();

    string getName() const;
    int getStudentCount() const;
    Student* getStudents() const;

    void addStudent(const Student& student, int index);

    friend ostream& operator<<(ostream& os, const Group& group);
    friend istream& operator>>(istream& is, Group& group);
};

#endif // GROUP_H
