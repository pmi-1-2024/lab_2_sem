#ifndef VACUUMCLEANER_H
#define VACUUMCLEANER_H
#include <iostream>
#include <string>
#include "Electroprilad.h"
#include <fstream>
using namespace std;

class Vacuumcleaner : virtual public Electroprilad
{
protected:
	int power;
	string color;
public:
	Vacuumcleaner();
	Vacuumcleaner(string n, string f, int pr, int p, string c);
	Vacuumcleaner(const Vacuumcleaner& vac);
	int Getpower()const;
	string GetColor()const;
	friend istream& operator>>(istream& is, Vacuumcleaner& vac);
	friend ostream& operator << (ostream & os, const Vacuumcleaner & vac);
	virtual void print(ostream& os)const;
	virtual void read(istream& is)override;

};
#endif
