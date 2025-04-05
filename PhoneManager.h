#ifndef PHONEMANAGER_H
#define PHONEMANAGER_H

#include "PhoneList.h"

class PhoneManager {
	Phone_List list;



public:
	void add(Phone* p);

	void removeByName(string name);
	void search(string name, ostream& out);
	void printAll(ostream& out);
};

#endif
