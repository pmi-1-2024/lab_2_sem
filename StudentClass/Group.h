#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <string>
#include "Student.h"
class Group
{
private:
	int studcount;
	Student* students;
	string name;
public:
	Group();
	Group(int sc, Student* studs, string name);
	void AddStudent(Student& student);
	void RemoveStudent(int number);
	friend istream& operator>>(istream& is, Group& group);
	friend ostream& operator<<(ostream& os, const Group& group);
};
#endif
