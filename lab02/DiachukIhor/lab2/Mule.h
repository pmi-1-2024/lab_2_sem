#ifndef MULE_H
#define MULE_H
#include "Horse.h"
#include "Donkey.h"

class Mule : public Animal {
private:
    std::string nickname;
public:
    Mule(const std::string& name, int year, const std::string& nickname);
    void print(std::ostream& out) const override;
};

#endif
