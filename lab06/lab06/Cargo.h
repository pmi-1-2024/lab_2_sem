#ifndef CARGO_H
#define CARGO_H

#include <string>
#include <iostream>

using namespace std;

class Cargo {
private:
    string type;

public:
    Cargo(const string& type = "");
    string getType() const;
    void setType(const string& newType);
    bool operator==(const string& str) const;

    friend ostream& operator<<(ostream& os, const Cargo& item);
    friend istream& operator>>(istream& is, Cargo& item);
};

#endif