#ifndef CARGOITEM_H
#define CARGOITEM_H

#include <iostream>
#include <string>
using namespace std;

class CargoItem {
public:
	char type;
	string name;
	string destination;
	double cost;
	double weight;
	string condition;

	void readFromFile(istream& is) {
		is >> type >> name >> destination >> cost >> weight;
		if (type == 's') { is >> condition; }
		else { condition = "-"; }
	}
};
#endif

