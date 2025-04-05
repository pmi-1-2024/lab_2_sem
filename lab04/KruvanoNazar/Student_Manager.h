#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H
#include <iostream>
#include <string>
using namespace std;
#include "Student_list.h"
class Student_Manager 
{
private:
	Student_list studlist;
public:
	void addstudent(const Student& s);
	Student_link* findstudent(const Student& s);
	void removestudent(const Student& s);
	void insertstudent(const Student& oldd, const Student& newd);
	void printstuds();

};
#endif
