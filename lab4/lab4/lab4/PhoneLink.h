#ifndef PHONELINK_H
#define PHONELINK_H

#include "Link.h"
#include "Phone.h"

struct Phone_Link : public Link {
	Phone* data;
	Phone_Link(Phone* p) { data = p; }
};

#endif
