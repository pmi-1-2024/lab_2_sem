#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include "student.h"

using namespace std;

class Group {
private:
	string name;
	int index;
	int capacity;
	Student* list;
public:
	Group();
	Group(const Group& other_g);
	void add(Student st);
	Student* get_list();
	int get_size();
	friend ostream& operator << (ostream& out, const Group& p);
	Student& operator[](int);
	Group& operator=(const Group& other_g);

	~Group();
};
#endif