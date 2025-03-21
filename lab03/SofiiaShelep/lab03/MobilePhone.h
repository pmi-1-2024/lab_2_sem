#pragma once
#include "Phone.h"

class MobilePhone : virtual public Phone
{
protected:
	string color;
	int memory;

public:
	MobilePhone();
	MobilePhone(string name, string brand, double price, string color, int memory);
	string getColor();
	void setColor(string color);
	int getMemory();
	void setMemory(int memory);
	~MobilePhone() {};
	void read(istream& in);
	void write(ostream& out) const;
};