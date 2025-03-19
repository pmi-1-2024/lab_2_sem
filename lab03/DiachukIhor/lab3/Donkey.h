
#ifndef DONKEY_H
#define DONKEY_H
#include "Animal.h"

using namespace std;

class Donkey : public Animal {
private:
    string species;
    double height;
public:
    Donkey(const string& name, int year, const string& species, double height);
    void print(ostream& out) const override;
    double getHeight() const;
};

#endif