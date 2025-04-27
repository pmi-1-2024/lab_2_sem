#ifndef TRANSPORTSABS_H
#define TRANSPORTSABS_H
#include <iostream>
#include "Cargo.h"
#include "Passenger.h"
using namespace std;
class TransportsABS
{
public:
	virtual ~TransportsABS(){}
	virtual string GetDest() = 0;
	virtual string GetType() = 0;
	virtual double GetCost() = 0;
	virtual void SetVantag() = 0;
	virtual bool GetDiscount() = 0;
	virtual void SetCost(double c) = 0;
	virtual void SetDest(string d) = 0;
	virtual double Discount() = 0;
	virtual double FinalCost() = 0;
	virtual void print(ostream& os)const = 0;
	virtual void read(istream& is) = 0;
	friend ostream& operator <<(ostream& os, const TransportsABS& tabs) {
		tabs.print(os);
		return os;
	}
	friend istream& operator>>(istream& is, TransportsABS& tabs) {
		tabs.read(is);
		return is;
	}
};
#endif
