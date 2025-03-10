#ifndef GROUP_H
#define GROUP_H
#include <fstream> 
#include "Student.h"
#include "Utils.h"

class Group
{
private:
	string name;
	Student* students;
	int studentCount;
public:
	Group();
	Group(string name, Student* student, int studentCount);
	Group(const Group& group);
	Group& operator=(const Group& group);
	Student& operator[](int index);
	~Group();

	void saveToFile(const string& filename);
	void addStudents(const Student* students, int count);
	void addStudent(const Student& student);
	void removeStudent(string studentName);

	string getName() const;
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
