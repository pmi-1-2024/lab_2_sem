#ifndef RADIOPHONE_H
#define RADIOPHONE_H

#include "Phone.h"
using namespace std;

class RadioPhone :virtual public Phone {
protected:
    double range;
    bool answeringMachine;

public:
    RadioPhone(string n, string b, double p, double r, bool a);
    //void display() const override;
    bool hasAnsweringMachine() const override;

    void read(istream& in) override {
        in >> name >> brand >> price >> range >> answeringMachine;
    }

    void display() const override {
        cout << "RadioPhone: " << name << ", " << brand << ", " << price
            << ", Range: " << range << "m, "
            << (answeringMachine ? "Answering Machine: Yes" : "Answering Machine: No") << endl;
    }


    friend istream& operator>>(istream& in, RadioPhone& rp);
    friend ostream& operator<<(ostream& out, const RadioPhone& rp);
};


#endif 
