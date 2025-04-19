#ifndef MEGAPHONE_H
#define MEGAPHONE_H
#include "MobilePhone.h"
#include "RadioPhone.h"

class MegaPhone : public MobilePhone, public RadioPhone {
public:
    MegaPhone();
    MegaPhone(string n, string b, double p, string c, int m, double r, bool a)
        : Phone(n, b, p), MobilePhone(n, b, p, c, m), RadioPhone(n, b, p, r, a) {}

    bool hasAnsweringMachine() const override {
        return RadioPhone::hasAnsweringMachine();
    }

   void read(istream& in) override {
        MobilePhone::read(in);  
        in >> range >> answeringMachine; 
    }

    void display() const override {
        cout << "MegaPhone: " << name << ", " << brand << ", " << price << ", "
            << color << ", " << memory << "GB, Range: " << range << "m, "
            << (answeringMachine ? "Answering Machine: Yes" : "Answering Machine: No")
            << endl;

    }

   
};

#endif