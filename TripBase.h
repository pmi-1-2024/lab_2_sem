#ifndef TRIPBASE_H
#define TRIPBASE_H

#include <string>
#include <iostream>
using namespace std;

class TripBase {
public:
	virtual ~TripBase() {}
	virtual void input(istream& in) = 0;
	virtual void output(ostream& out)const = 0;

	virtual double getCost()const = 0;
	virtual string getType()const = 0;
	virtual void update() = 0;
	virtual void applySale() = 0;
};

#endif
