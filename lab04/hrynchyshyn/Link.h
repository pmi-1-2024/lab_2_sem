#pragma once

#include "Student.h"

struct Link {
	Link* next;
	virtual ~Link() {}
protected:
	Link() : next(0) {}
};

struct Student_Link : Link {
	Student data;
	Student_Link(const Student& d) : data(d) {}
};
