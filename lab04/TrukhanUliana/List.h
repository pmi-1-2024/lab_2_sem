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

struct Student_Link : Link {
	string name;
	string surname;
	double aver;
	Student_Link(string n = " ", string sn = " ", double a = 0.0) : name(n), surname(sn), aver(a) {}

	friend ostream& operator<<(ostream& os, const Student_Link& student);
	friend istream& operator>>(istream& is, Student_Link& student);
};

class List {
private:
	List(const List&);
	List& operator=(const List&);
protected:
	Link* head;
	void add(Link*);
	Link* top()const { return head; }

public:
	List() : head(0) {}
	~List();
	Link* remove(Link* node = 0);
	bool empty() const { return !head; }
};

#endif