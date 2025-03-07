#include "MobilePhone.h"

MobilePhone::MobilePhone(string name, string brand, double price, string color, int memory)
{
	this->name = name;
	this->brand = brand;
	this->price = price;
	this->color = color;
	this->memory = memory;

}

string MobilePhone::getColor()
{
    return color;
}

void MobilePhone::setColor(string color)
{
	this->color = color;
}

int MobilePhone::getMemory()
{
    return memory;
}

void MobilePhone::setMemory(int memory)
{
	this->memory = memory;
}
