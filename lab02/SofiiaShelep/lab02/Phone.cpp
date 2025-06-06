#include "Phone.h"
#include <iostream>
using namespace std;

Phone::Phone()
{
	name = "";
	brand = "";
	price = 0;
}

Phone::Phone(string name, string brand, double price)
{
	this->name = name;
	this->brand = brand;
	this->price = price;
}

void Phone::setName(string name)
{
	this->name = name;
}

string Phone::getName()
{
	return name;
}

void Phone::setBrand(string brand)
{
	this->brand = brand;
}

string Phone::getBrand()
{
	return brand;
}

void Phone::setPrice(double price)
{
	this->price = price;
}

double Phone::getPrice()
{
	return price;
}

Phone::~Phone()
{
}

bool Phone::operator<(const Phone& other) const
{
	return price < other.price;
}

bool Phone::operator>(const Phone& other) const
{
	return false;
}

std::istream& operator>>(std::istream& in, Phone& phone)
{
	phone.read(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Phone& phone)
{
	phone.write(out);
	return out;
}