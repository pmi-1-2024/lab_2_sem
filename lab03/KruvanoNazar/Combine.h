#ifndef COMBINE_H
#define COMBINE_H
#include <iostream>
#include <string>
#include "Electroprilad.h"
#include <fstream>
class Combine : virtual public Electroprilad {
protected:
	int cpower;
	int countf;
public:
	Combine();
	Combine(string n, string f, int p, int cp, int cou);
	Combine(const Combine& com);
	int GetCombinePower()const;
	int GetCountOfFunctions()const;
	virtual void print(ostream& os)const ;
	virtual void read(istream& is)override;
};
#endif