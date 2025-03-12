#include "HybridPhone.h"

HybridPhone::HybridPhone()
{

}

HybridPhone::HybridPhone(string name, string brand, double price, string color, int memory, double range, bool answeringMachine)
	: Phone(name, brand, price), MobilePhone(name, brand, price, color, memory), RadioPhone(name, brand, price, range, answeringMachine)
{
	
}

void HybridPhone::read(istream& in)
{
	in >> name >> brand >> price >> color >> memory >> range >> answeringMachine;
}

