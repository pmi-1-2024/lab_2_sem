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

	virtual ~Phone() = 0;
	virtual void read(istream& in) = 0;
	virtual void write(ostream& out) const = 0;
	bool operator<(const Phone& other) const;
	bool operator>(const Phone& other) const;
};

std::istream& operator>>(std::istream& in, Phone& phone);
std::ostream& operator<<(std::ostream& out, const Phone& phone);