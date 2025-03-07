#pragma once
#include "Phone.h"
class RadioPhone : public Phone
{
	double range;
	bool answeringMachine;
public:
	RadioPhone();
	RadioPhone(string name, string brand, double price, double range, bool answeringMachine);
	void setRange(double range);
	double getRange();
	void setAnsweringMachine(bool answeringMachine);
	bool getAnsweringMachine();	
};

