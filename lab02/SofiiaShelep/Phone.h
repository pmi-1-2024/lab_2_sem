#pragma once
#include <iostream>
#include <string>	
using namespace std;

class Phone
{
protected:
	string name;
	string brand;
	double price;


public:
	Phone();
	Phone(string name, string brand, double price);
	void setName(string name);
	string getName();
	void setBrand(string brand);
	string getBrand();
	void setPrice(double price);
	double getPrice();

	virtual ~Phone() {};

};


