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
	}

	Zalicovca(const Zalicovca& other_z) {
		size = other_z.size;
		array = new Predmet[size];
		for (int i = 0; i < size; i++) array[i] = other_z.array[i];

	}
	string get_id();
	int get_size();
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