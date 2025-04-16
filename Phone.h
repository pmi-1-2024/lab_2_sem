#ifndef PHONE_H
#define PHONE_H

#include <iostream>
#include <string>

using namespace std;

class Phone {
protected:
    string name;
    string brand;
    double price;
public:
    Phone() : name(""), brand(""), price(0) {}
    virtual ~Phone() {}

    virtual void read(istream& in) = 0;
    virtual void write(ostream& out) const = 0;

    double getPrice() const { return price; }
    string getName() const { return name; }

    friend istream& operator>>(istream& in, Phone& p) {
        p.read(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Phone& p) {
        p.write(out);
        return out;
    }
};

class MobilePhone : public Phone {
private:
    string color;
    int memory;
public:
    void read(istream& in) override {
        in >> name >> brand >> price >> color >> memory;
    }
    void write(ostream& out) const override {
        out << "MobilePhone: " << name << " " << brand << " " << price
            << " " << color << " " << memory << endl;
    }
};

class RadioPhone : public Phone {
private:
    double range;
    bool answeringMachine;
public:
    void read(istream& in) override {
        in >> name >> brand >> price >> range >> answeringMachine;
    }
    void write(ostream& out) const override {
        out << "RadioPhone: " << name << " " << brand << " " << price
            << " " << range << " " << (answeringMachine ? "Yes" : "No") << endl;
    }
};

#endif
