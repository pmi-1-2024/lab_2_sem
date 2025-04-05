#ifndef PHONELIST_H
#define PHONELIST_H

#include "List.h"
#include "PhoneLink.h"
#include <iostream>


using namespace std;

class Phone_List : public List {
public:
	void push(Phone* p);
	Phone_Link* findByName(string name);
	void printAll(ostream& out);


};

#endif
