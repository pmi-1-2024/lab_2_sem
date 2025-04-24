#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	string surname;
	int aver;

	Student();
	bool operator >(const Student& student) const;
	bool operator <(const Student& student) const;
	friend ostream& operator<<(ostream& os, const Student& student);
	friend istream& operator>>(istream& is, Student& student);
};

#endif // !STUDENT_H
