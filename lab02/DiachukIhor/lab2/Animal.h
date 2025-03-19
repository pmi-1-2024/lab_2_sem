#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class Animal {
protected:
    std::string name;
    int birthYear;
public:
    Animal(const std::string& name, int year);
    virtual ~Animal() = default;
    int getBirthYear() const;
    virtual void print(std::ostream& out) const = 0;
};

#endif
