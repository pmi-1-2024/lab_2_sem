#pragma once
#include"Student.h"
class Group {
private:
	string namegroup;
	Student* groupa;
	int size;
public:
	Group();
	Group(string namegroup,int size, Student* groupa);
	void display() const;
	void read(istream& is);
	string getnamegroup() const;
	friend istream& operator>>(istream& is,Group& g);
};
