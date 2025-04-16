#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H
#include "Student_List.h"
class Student_Manager
{
private:
	Student_List list;
public:
	void addStud(const Student& student);
	void removeStud(const Student& student);
	Student_Link* findStud(const Student& student);
	void replaceStud(const Student& oldData, const Student& newData);
	void printStud();
};

#endif