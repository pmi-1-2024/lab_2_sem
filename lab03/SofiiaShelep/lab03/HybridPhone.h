#pragma once
#include <iostream>
#include "MobilePhone.h"
#include "RadioPhone.h"
using namespace std;

class HybridPhone : public MobilePhone, public RadioPhone
{
public:
	HybridPhone();
	HybridPhone(string name, string brand, double price, string color, int memory, double range, bool answeringMachine);
	~HybridPhone() {};
	void read(istream& in);
	void write(ostream& out) const;
};