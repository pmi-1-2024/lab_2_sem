#ifndef CARGO_H
#define CARGO_H

#include <iostream>
#include <string>
using namespace std;

struct Passenger {
	int age;
	bool hasBags;
	Passenger() { age = 0; hasBags = 0; }

	void read(istream& in) { in >> age >> hasBags; }
	void print(ostream& out)const { out << "Passenger age:" << age << " bags:" << hasBags; }

	string type()const { return "passenger"; }
};

struct Package {
	int weight;
	string kind;
	Package() { weight = 0; kind = ""; }

	void read(istream& in) { in >> weight >> kind; }
	void print(ostream& out)const { out << "Package " << kind << " weight:" << weight; }

	string type()const { return "package"; }
};

#endif
