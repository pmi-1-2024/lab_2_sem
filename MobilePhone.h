#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include "Phone.h"


class MobilePhone : public Phone {

	string color;
	int memory;

public:
	MobilePhone();


	void read(istream& in);
	void write(ostream& out)const;
};

#endif
