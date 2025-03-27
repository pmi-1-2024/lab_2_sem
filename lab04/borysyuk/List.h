#pragma once
#include "Link.h"

class List
{
private:
	List(const List&);
	List& operator= (const List&);
protected:
	Link* head;
	void push(Link*);
	Link* top()const;
public:
	List();
	~List();
	Link* remove(Link* node = 0);
	bool empty()const;
};