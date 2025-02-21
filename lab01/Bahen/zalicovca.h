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
		this->id = "0";
        this->size = 0;
		this->array = 0;
    }
	string get_id();
	friend ostream& operator << (ostream& out, const Zalicovca& z);
	friend istream& operator >> (istream& in, Zalicovca& z);
};

#endif