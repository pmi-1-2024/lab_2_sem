#ifndef ELECTROPRILAD_H
#define ELECTROPRILAD_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Electroprilad {
protected:
	string name;
	string firm;
	int price;
public:
	Electroprilad();
	Electroprilad(string n, string f, int p);
	Electroprilad(const Electroprilad& elp);
	string GetName() const;
	string GetFirm() const;
	int GetPrice() const;
	friend istream& operator >>(istream& is, Electroprilad& elp);
	friend ostream& operator <<(ostream& os, const Electroprilad& elp);
	bool operator<(const Electroprilad& elp) const;
	virtual void print(ostream& os)const;
	virtual void write(istream& is)=0;
	virtual ~Electroprilad(){}
};
#endif
