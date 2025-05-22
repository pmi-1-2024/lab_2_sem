#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cargo {
public:
    virtual ~Cargo() {}
    virtual void print(ostream& os) const = 0;
    friend ostream& operator<<(ostream& os, const Cargo& c) {
        c.print(os);
        return os;
    }
};

class Person : public Cargo {
private:
    string name;
public:
    Person() : name("") {}
    Person(string n) : name(n) {}
    string getName() const { return name; }
    void print(ostream& os) const override {
        os << "Person: " << name;
    }
};

class Goods : public Cargo {
private:
    string type;
    double weight;
public:
    Goods() : type(""), weight(0.0) {}
    Goods(string t, double w) : type(t), weight(w) {}
    string getType() const { return type; }
    double getWeight() const { return weight; }
    void print(ostream& os) const override {
        os << "Goods: " << type << " (" << weight << " kg)";
    }
};
