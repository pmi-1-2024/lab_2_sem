#include "Student.h"

Student::Student() : name(""), group(""), recordNumber("") {}

Student::Student(string name, string group, string recordNumber)
	: name(name), group(group), recordNumber(recordNumber) {
}

istream& operator>>(istream& in, Student& student) {
	cout << "Enter student's name: ";
	getline(in, student.name);
	cout << "Enter group name: ";
	getline(in, student.group);
	cout << "Enter record number: ";
	getline(in, student.recordNumber);
	return in;
}

ostream& operator<<(ostream& out, const Student& student) {
	out << "Name: " << student.name << "\n";
	out << "Group: " << student.group << "\n";
	out << "Record Number: " << student.recordNumber << "\n";
	return out;
}

const string& Student::getName() const { return name; }
const string& Student::getGroup() const { return group; }
const string& Student::getRecordNumber() const { return recordNumber; }
