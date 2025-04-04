#ifndef WASHMASH_H
#define WASHMASH_H
#include <iostream>
#include <string>
#include "Electroprilad.h"
#include <fstream>
class Washmash : virtual public Electroprilad{
protected:
	int countop;
	int capacity;
public:
	Washmash();
	Washmash(string n, string f, int pr, int cou, int cap);
	Washmash(const Washmash& wash);
	int GetCountOfPrograms()const;
	int GetCapacity()const;
	virtual void print(ostream& os)const;
	virtual void read(istream& is)override;

};
#endif