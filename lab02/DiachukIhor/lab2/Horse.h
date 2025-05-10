#ifndef HORSE_H
#define HORSE_H
#include "Animal.h"

class Horse : public Animal {
private:
    std::string color;
    std::string breed;
public:
    Horse(const std::string& name, int year, const std::string& color, const std::string& breed);
    void print(std::ostream& out) const override;
    const std::string& getColor() const;
};

#endif
