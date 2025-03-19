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
	friend istream& operator>>(istream& is, Washmash& wash);
	friend ostream& operator<<(ostream& os, const Washmash& wash);
	virtual void print(ostream& os)const;
	virtual void write(istream& is)override;

};
#endif