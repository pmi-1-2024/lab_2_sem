#ifndef BILL_H
#define BILL_H
#include <iostream>
using namespace std;
class Bill
{
protected:
	string surname;
	double amountpaid;
public:
	virtual ~Bill() {}
	string GetSurname()const {
		return surname;
	 }
	double GetAmPaid() const {
		return amountpaid;
	}
	virtual void print(ostream& os) const  = 0;
	virtual void read(istream& is) = 0;
	friend istream& operator>>(istream& is, Bill& b) {
		b.read(is);
		return is;
	}
	friend ostream& operator <<(ostream& os, const Bill& b) {
		b.print(os);
		return os;
	}

};
#endif
