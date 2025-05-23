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
	Phone();
	~Phone();

	void read(istream& in);
	void write(ostream& out) const;

	string getName() const;
	string getBrand() const;
	double getPrice() const;
};

#endif
