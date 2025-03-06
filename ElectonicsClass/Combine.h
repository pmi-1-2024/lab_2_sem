#ifndef COMBINE_H
#define COMBINE_H
#include <iostream>
#include <string>
#include "Electroprilad.h"
#include <fstream>
class Combine : public Electroprilad {
private:
	int cpower;
	int countf;
public:
	Combine();
	Combine(string n, string f, int p, int cp, int cou);
	Combine(const Combine& com);
	friend istream& operator>>(istream& is, Combine& com);
	friend ostream& operator<<(ostream& os, const Combine& com);
	virtual void print(ostream& os)const ;
	virtual istream& write(istream& is)override;
};
#endif