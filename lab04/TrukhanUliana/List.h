#ifndef LIST_H
#define LIST_H
#include "Student_Link.h"

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