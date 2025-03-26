#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include <iostream>
#include <string>
#include "List.h"
#include "Student.h"
using namespace std;

class Student_list : public List
{
public:
	void push(Student s);	
	Student_link* top()const;
	Student_link* find(const Student& s);
	void insert(Student a, Student_link* after);
};
#endif
