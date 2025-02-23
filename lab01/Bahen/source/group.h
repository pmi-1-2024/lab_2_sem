#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include "student.h"
#include "constants.h"

using namespace std;

class Group {
private:
	string name;
	int size;
	Student* list;
public:
	Group() {
		name = "";
		size = 0;
		list = new Student[n];
	};
	Group(string n, int s) {
		name = n;
		size = 0;
		list = new Student[s];
	};
	void add(Student st);
	Student* get_list();
	int get_size();
	friend ostream& operator << (ostream& out, const Group& p);

};
#endif