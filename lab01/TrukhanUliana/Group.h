#ifndef GROUP_H
#define GROUP_H
#include <fstream> 
#include "Student.h"

class Group
{
private:
	string name;
	Student* students;
	int studentCount;
public:
	Group();
	Group(string name, Student* student, int studentCount);
	~Group();

	void addStudent(const Student& student);
	void addStudents(const Student* students, int count);
	void removeStudent(string studentName);
	void display() const;

	int getStudentCount() const;
	Student* getStudents() const;

	void searchByGroupName(const string& groupName) const;
	void searchByAddress(const Address& address) const;
	void searchByRecordNumber(const string& recordNumber) const;
	void searchBySubjectName(const string& subjectName) const;

	friend istream& operator>>(istream& is, Group& group);
	friend ostream& operator<<(ostream& os, const Group& group);
};

#endif
