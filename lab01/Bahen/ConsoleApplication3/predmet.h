#ifndef PREDMET_H
#define PREDMET_H
#include <iostream>
using namespace std;

class Predmet {
private:
	string name;
	int term;
	int mark;
public:
	Predmet() {
		this->name = "";
		this->term = 1;
		this->mark = 0;
	}
	friend ostream& operator << (ostream& out, const Predmet& p);
	friend istream& operator >> (istream& in, Predmet& p);
};

#endif