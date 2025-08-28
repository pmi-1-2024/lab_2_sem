#ifndef PHONE_H
#define PHONE_H

#include <iostream>
#include <string>

using namespace std;

class Phone {
protected:
    string firm;
    string name;
    int price;
public:
    Phone();
    Phone(const Phone & other);
    string get_name();
    string get_firm();
    virtual string get_type();
    int get_price();
    void set_price(int a);
    virtual void print(ostream& out) = 0;
    virtual void input(istream& in) = 0;
    friend ostream& operator << (ostream& out, Phone& ph);
    friend istream& operator >> (istream& in, Phone& ph);
    virtual ~Phone(){}
};
#endif
