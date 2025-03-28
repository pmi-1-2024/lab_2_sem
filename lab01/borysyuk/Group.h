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
	
	Group(const Group& other);

	
	Group& operator=(const Group& other);

	
	Student& operator[](int index);
	const Student& operator[](int index) const;

	
	~Group();

	void display(ostream& os) const;
	void read(istream& is);
	string getnamegroup() const;
	friend istream& operator>>(istream& is,Group& g);
	friend ostream& operator<<(ostream& os, const Group& g);
};
