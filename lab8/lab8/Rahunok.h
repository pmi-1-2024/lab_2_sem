#pragma once
#include <string>
#include <iostream>

using namespace std;

class Rahunok {
protected:
    string surname;
    double paidAmount;

public:
    Rahunok(string surname = "", double paidAmount = 0.0)
        : surname(surname), paidAmount(paidAmount) {}

    virtual ~Rahunok() {}

    string getSurname() const { 
        return surname; 
    }

    double getPaidAmount() const { 
        return paidAmount; 
    }

    virtual string getType() const = 0;
   
    virtual void read(istream& is) = 0;
    friend istream& operator>>(istream& is, Rahunok& b) {
        b.read(is);
        return is;
    }
   
    virtual void print(ostream& os) const = 0;
    friend ostream& operator<<(ostream& os, const Rahunok& b) {
        b.print(os);
        return os;
    }  
};
