#include "RadioPhone.h"

RadioPhone::RadioPhone()
{
	range = 0;
	answeringMachine = false;
}

RadioPhone::RadioPhone(string name, string brand, double price, double range, bool answeringMachine)
{
	this->name = name;
	this->brand = brand;
	this->price = price;
	this->range = range;
	this->answeringMachine = answeringMachine;
}

void RadioPhone::setRange(double range)
{
	this->range = range;
}

double RadioPhone::getRange()
{
	return range;
}

void RadioPhone::setAnsweringMachine(bool answeringMachine)
{
	this->answeringMachine = answeringMachine;
}

bool RadioPhone::getAnsweringMachine()
{
	return answeringMachine;
}

void RadioPhone::read(istream& in)
{
	in >> name >> brand >> price >> range >> answeringMachine;
}

void RadioPhone::write(ostream& out) const
{
	out << name << " " << brand << " " << price << " " << range << " " << answeringMachine;
}