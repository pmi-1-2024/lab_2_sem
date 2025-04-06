#include "link.h"
#include "student.h"
using namespace std;

class SLink: public Link{
public:
	Student val;
	SLink():Link(){};
	SLink(Link* l, Student s):Link(l){val  = s;}
	~ SLink(){};
};
