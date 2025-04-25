#ifndef STUDENTSTRUCT_H
#define STUDENTDTRUCT_H
#include <iostream>
#include <string>
using namespace std;

struct Student {
private:
	string name;
	string surname;
	int mark;
public:
	Student();
	bool operator >(const Student& stud);
	friend istream& operator >>(istream& is, Student& stud);
	friend ostream& operator << (ostream& os, const Student& stud);
	string GetSurname();
};
#endif