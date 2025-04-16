#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

struct Student {
	string name;
	string surname;
	double aver;
	Student(string n = " ", string sn = " ", double a = 0.0) : name(n), surname(sn), aver(a) {}

	friend ostream& operator<<(ostream& os, const Student& student);
	friend istream& operator>>(istream& is, Student& student);
};
#endif