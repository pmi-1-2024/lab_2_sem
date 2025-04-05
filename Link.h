#ifndef LINK_H
#define LINK_H

struct Link {
	Link* next;
	virtual ~Link() {}

protected:
	Link() { next = 0; }
};

#endif
