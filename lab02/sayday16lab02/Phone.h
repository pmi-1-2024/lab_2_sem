#ifndef PHONE_H
#define PHONE_H

#include <iostream>
using namespace std;

class Phone {
protected:
    string name;
    string brand;
    double price;

public:
    Phone();
    Phone(string n, string b, double p);
    virtual ~Phone();

    virtual void display() const = 0;
    virtual bool hasAnsweringMachine() const;

    double getPrice() const; 
    
    bool operator<(const Phone& other) const {
        return this->getPrice() < other.getPrice();
    }




    friend istream& operator>>(istream& is, Phone*& phone);
        
    
    friend ostream& operator<<(ostream& out, const Phone& phone);
};

#endif





