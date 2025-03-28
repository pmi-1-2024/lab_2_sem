#pragma once
#include "Link.h"
#include <iostream>
using namespace std;

class List {
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
	bool empty()const { return !head; }
};

class Phone_list : public List {
public:
	void push(Phone a);
	Phone top() const { return((Phone_link*)head)->data; }
	Phone_link* find(Phone a);
	void insert(Phone a, Phone_link* after);
};
