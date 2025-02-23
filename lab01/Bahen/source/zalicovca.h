#ifndef ZALICOVCA_H
#define ZALICOVCA_H

#include <iostream>
#include "predmet.h"

class Zalicovca {
private:
	string id;
	int size;
	Predmet * array;
public:
	Zalicovca() {
		id = "0";
		size = 0;
		array = 0;
	};
	string get_id();
	bool is_subject(string sub);
	friend ostream& operator << (ostream& out, const Zalicovca& z);
	friend istream& operator >> (istream& in, Zalicovca& z);
};

#endif