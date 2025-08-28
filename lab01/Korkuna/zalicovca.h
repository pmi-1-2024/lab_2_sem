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
	Zalicovca();
	Zalicovca(const Zalicovca& other_z);
	string get_id();
	bool is_subject(string sub);
	friend ostream& operator << (ostream& out, const Zalicovca& z);
	friend istream& operator >> (istream& in, Zalicovca& z);
	Predmet& operator[](int);
	Zalicovca& operator=(const Zalicovca& other_z);

	~Zalicovca() {
		delete[] array;
	}
};

#endif