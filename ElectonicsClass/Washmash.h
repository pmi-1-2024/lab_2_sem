#ifndef WASHMASH_H
#define WASHMASH_H
#include <iostream>
#include <string>
#include "Electroprilad.h"
#include <fstream>
class Washmash : public Electroprilad{
private:
	int countop;
	int capacity;
public:
	Washmash();
	Washmash(string n, string f, int pr, int cou, int cap);
	Washmash(const Washmash& wash);
	friend istream& operator>>(istream& is, Washmash& wash);
	friend ostream& operator<<(ostream& os, const Washmash& wash);
	virtual void print(ostream& os)const;
	virtual istream& write(istream& is)override;

};
#endif