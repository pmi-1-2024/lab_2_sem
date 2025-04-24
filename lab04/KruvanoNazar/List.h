#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include "Links.h"
using namespace std;

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
#endif