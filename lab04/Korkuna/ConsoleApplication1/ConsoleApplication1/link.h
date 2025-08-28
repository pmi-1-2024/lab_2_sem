#include <iostream>
using namespace std;

class Link {
public:
	Link* next;
	Link() { next = nullptr; }
	Link(Link* l) { next = l; }
	virtual ~Link() {};
};
