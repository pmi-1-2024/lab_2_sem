#ifndef RADIOPHONE_H
#define RADIOPHONE_H

#include "Phone.h"

class RadioPhone : public Phone {

	double range;
	bool answer;

public:

	RadioPhone();

	void read(istream& in);
	void write(ostream& out)const;
};

#endif
