#ifndef HORSE_H
#define HORSE_H
#include "Animal.h"

using namespace std;

class Horse : public Animal {
private:
    string color;
    string breed;
public:
    Horse(const string& name, int year, const string& color, const string& breed);
    void print(ostream& out) const override;
    const string& getColor() const;
};

#endif