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
	~Phone();

	friend std::istream& operator>>(std::istream& in, Phone& phone);
	friend std::ostream& operator<<(std::ostream& out, const Phone& phone);
	bool operator==(const Phone& phone) const
	{
		return name == phone.name && brand == phone.brand && price == phone.price;
	}
};
