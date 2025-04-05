#include "Student.h"

ostream& operator<<(ostream& os, const Student& student) {
	os << "Name: " << student.name
		<< ", Surname: " << student.surname
		<< ", Average grades: " << student.aver;
	return os;
}

istream& operator>>(istream& is, Student& student) {
	cout << "Enter student's name: ";
	is >> student.name;
	cout << "Enter student's surname: ";
	is >> student.surname;
	cout << "Enter student's average grades: ";
	is >> student.aver;
	return is;
}
