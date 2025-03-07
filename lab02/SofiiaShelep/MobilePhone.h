#pragma once
#include "Phone.h"

class MobilePhone : public Phone 
{
	string color;
	int memory;

public:
	MobilePhone(string name, string brand, double price, string color, int memory);
	string getColor();
	void setColor(string color);
	int getMemory();
	void setMemory(int memory);

};

