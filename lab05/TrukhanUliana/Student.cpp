#include "Student.h"

Student::Student() : name(" "), surname(" "), aver(0) {}

bool Student::operator >(const Student& student) const {
	if (aver != student.aver) return aver > student.aver;
	if (surname != student.surname) return surname > student.surname;
	return name > student.name;
}

bool Student::operator <(const Student& student) const {
	if (aver != student.aver) return aver < student.aver;
	if (surname != student.surname) return surname < student.surname;
	return name < student.name;
}

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
	is.ignore();
	return is;
}
