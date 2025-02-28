#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include "student.h"
#include "constants.h"

using namespace std;

class Group {
private:
	string name;
	int index;
	int capacity;
	Student* list;
public:
	Group() {
		name = "";
		index = 0;
		capacity = 8;
		list = new Student[capacity];
	};
	Group(string n, int s) {
		name = n;
		index = 0;
		capacity = s;
		list = new Student[s];
	};
	void add(Student st);
	Student* get_list();
	int get_size();
	friend ostream& operator << (ostream& out, const Group& p);
	Student& operator[](int);

	~Group() {
		delete[] list;
	}
};
#endif