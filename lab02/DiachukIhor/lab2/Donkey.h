#ifndef DONKEY_H
#define DONKEY_H
#include "Animal.h"

class Donkey : public Animal {
private:
    std::string species;
    double height;
public:
    Donkey(const std::string& name, int year, const std::string& species, double height);
    void print(std::ostream& out) const override;
    double getHeight() const;
};

#endif
