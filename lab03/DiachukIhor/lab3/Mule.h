#ifndef MULE_H
#define MULE_H
#include "Horse.h"
#include "Donkey.h"

using namespace std;

class Mule : public Animal {
private:
    string nickname;
public:
    Mule(const string& name, int year, const string& nickname);
    void print(ostream& out) const override;
};

#endif