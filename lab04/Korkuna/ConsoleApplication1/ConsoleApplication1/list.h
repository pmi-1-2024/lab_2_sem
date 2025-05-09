#include "s_link.h"
using namespace std;

class List {
public:
	Link* head;

	List();
	bool isEmpty();
	virtual Link* top();
	void push(Link* new_e);
	void pop(Link* to_del);
	virtual ~List() {};
};
