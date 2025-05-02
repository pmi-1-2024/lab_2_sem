#ifndef PHONE_H
#define PHONE_H

#include <iostream>
#include <string>
using namespace std;

class Phone {


protected:

	string name;
	string brand;

	double price;



public:


	Phone() { name = ""; brand = ""; price = 0; }
	virtual ~Phone() {}

	virtual void read(istream& in) = 0;
	virtual void write(ostream& out)const = 0;
	double getPrice() { return price; }
	string getName() { return name; }
	friend istream& operator>>(istream& in, Phone& p) {
		p.read(in);
		return in;
	}


	friend ostream& operator<<(ostream& out, const Phone& p) {
		p.write(out);
		return out;
	}
};

#endif
