#ifndef BILL_H
#define BILL_H
#include <iostream>
#include <string>
using namespace std;

class Bill {
protected:
    string surname;
    double paid_amount;

public:
	Bill(string surname = " ", double paid_amount = 0.0) : surname(surname), paid_amount(paid_amount) {}
    virtual ~Bill() {}

    string getSurname() const { return surname; }
    double getPaidAmount() const { return paid_amount; }
    virtual string getType() const = 0;

    virtual void read(istream& is) = 0;
    friend istream& operator>>(istream& is, Bill& b) {
        b.read(is);
        return is;
    }

    virtual void print(ostream& os) const = 0;
    friend ostream& operator<<(ostream& os, const Bill& b) {
        b.print(os);
        return os;
    }
};

#endif
