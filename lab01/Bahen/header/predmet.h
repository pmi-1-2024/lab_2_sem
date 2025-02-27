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
		name = "";
		term = 1;
		mark = 0;
	};
	string get_name();
	friend ostream& operator << (ostream& out, const Predmet& p);
	friend istream& operator >> (istream& in, Predmet& p);
};

#endif