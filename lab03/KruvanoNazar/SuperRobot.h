#ifndef SUPERROBOT_H
#define SUPERROBOT_H
#include <iostream>
#include <string>
#include "Electroprilad.h"
#include "Vacuumcleaner.h"
#include "Washmash.h"
#include "Combine.h"

class SuperRobot : public Vacuumcleaner, public Washmash, public Combine {
public:
	SuperRobot();
	SuperRobot(string n, string f, int p, int pow, string col, int cop, int cap, int cp, int cof);
	SuperRobot(const SuperRobot& sr);
	virtual void print(ostream& os)const;
	virtual void read(istream& is);
	friend istream& operator>>(istream& is, SuperRobot& sr);
	friend ostream& operator<<(ostream& os, SuperRobot& sr);

};
#endif

