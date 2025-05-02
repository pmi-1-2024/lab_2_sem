#pragma once
#include "Rahunok.h"
#include <string>
#include <iostream>

using namespace std;

class GasRah: public Rahunok {
private:
	int people;
public:
	GasRah() : Rahunok(), people(0) {};

	string getType() const override {
		return "Gas";
	}

	int getPeople() const {
		return people;
	}

	void read(istream& is)override {
		is >> surname >> people >> paidAmount;
	}

	void print(ostream& os) const override {
		os << "Gas rahunok | Surname: " << surname << ", Number of people: "
			<< people << ", Total paid: " << paidAmount;    
	}
};
