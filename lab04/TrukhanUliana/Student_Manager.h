#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H
#include "Student_List.h"
class Student_Manager
{
private:
	Student_List list;
public:
	void addStud(string name, string surname, double aver);
	void removeStud(string name, string surname);
	Student_Link* findStud(string name, string surname);
	void replaceStud(string oldName, string oldSurname, string newName, string newSurname, double newAv);
	void printStud();
};

#endif