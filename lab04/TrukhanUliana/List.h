#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct Link {
	Link* next;
	virtual ~Link() {}
protected:
	Link() : next(0) {}
};

struct Student {
	string name;
	string surname;
	double aver;
	Student(string n = " ", string sn = " ", double a = 0.0) : name(n), surname(sn), aver(a) {}

	friend ostream& operator<<(ostream& os, const Student& student);
	friend istream& operator>>(istream& is, Student& student);
};

struct Student_Link : Link {
	Student data;
	Student_Link(const Student& student) : data(student) {}
};

class List {
private:
	List(const List&);
	List& operator=(const List&);
protected:
	Link* head;
	void push(Link*);
	Link* top()const { return head; }

public:
	List() : head(0) {}
	~List();
	Link* remove(Link* node = 0);
	bool empty() const { return !head; }
};

#endif