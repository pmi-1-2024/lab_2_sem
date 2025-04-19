#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H

#include "Phone.h"
using namespace std;

class MobilePhone :virtual public Phone {
protected:
    string color;
    int memory;

public:
    MobilePhone();
    MobilePhone(string n, string b, double p, string c, int m);
    //void display() const override;


    void read(istream& in) override {
        in >> name >> brand >> price >> color >> memory;
    }

    void display() const override {
        cout << "MobilePhone: " << name << ", " << brand << ", " << price
            << ", " << color << ", " << memory << "GB\n";
    }


    friend ostream& operator<<(ostream& os, const MobilePhone& phone);

    friend istream& operator>>(istream& is, MobilePhone& phone);
};

#endif
