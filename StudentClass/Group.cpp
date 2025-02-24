#include "Group.h"
#include <iostream>
using namespace std;

Group::Group() : studcount(0), students(nullptr), name("noname") {}
Group::Group(int sc, Student* studs, string name) : studcount(sc), students(studs), name(name) {}

istream& operator>>(istream& is, Group& group) {
	cout << "\nEnter group name: ";
	is >> group.name;
	cout << "\nEnter count of students: ";
	is >> group.studcount;
	cout << "\nEnter students of group: ";
	delete []group.students;
	group.students = new Student[group.studcount];
	for (int i = 0; i < group.studcount; i++) {
		cin>>group.students[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const Group& group)
{
	os << "\nGroup name: " << group.name;
	os << "\nCount of students: " << group.studcount;
	os << "\nStudents of group: ";
	for (int i = 0; i < group.studcount; i++) {
		cout << group.students->GetName();
	}
	return os;
}

void Group:: AddStudent(Student& student) {
	Student* newstudents = new Student[studcount + 1];
	for (int i = 0; i < studcount; i++) {
		newstudents[i] = students[i];
	}
	newstudents[studcount] = student;
	delete[]students;
	students = newstudents;
	studcount++;
}

void Group::RemoveStudent(int number)
{
	Student* newstudents = new Student[studcount - 1];

	for (int i = 0,j = 0; i < studcount; i++) {
		if (i != number - 1) {
			newstudents[j++] = students[i];
		}
	}
	delete[]students;
	students = newstudents;
	studcount--;
}