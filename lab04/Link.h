#pragma once
#include "Phone.h"
#include <iostream>
using namespace std;

struct Link {
	Link* next;
	virtual ~Link() {}
protected:
	Link() : next(0) {}
};

struct Phone_link : Link {
	Phone data;
	Phone_link(Phone d) : data(d) {}
};
