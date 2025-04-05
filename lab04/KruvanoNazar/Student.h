#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
	string name;
	string group;
	double avarage_mark;
public:
	Student();
	Student(string n, string g, double avm);
	Student(const Student& stud);
	friend istream& operator>>(istream& is, Student& stud);
	friend ostream& operator<<(ostream& os, const Student& stud);
	Student& operator =(const Student& st);
	bool operator==(const Student& other) const;
	string GetName() const;
	string GetGroup() const;
	double GetAvM() const;
};
#endif
