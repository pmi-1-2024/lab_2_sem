#ifndef LIST_H
#define LIST_H

#include "Link.h"


class List {

protected:
	Link* head;


public:
	List();
	~List();
	void push(Link* node);

	Link* remove(Link* node = 0);
	bool empty();
};

#endif
