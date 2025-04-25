#ifndef MULE_H
#define MULE_H

#include "Horse.h"
#include "Donkey.h"

class Mule : public Horse, public Donkey {
    string nickname;

public:
    Mule(const string& name = "", int birthYear = 0,
        const string& color = "", const string& breed = "",
        const string& type = "", double height = 0,
        const string& nickname = "")
        : Animal(name, birthYear), Horse(name, birthYear, color, breed),
        Donkey(name, birthYear, type, height), nickname(nickname) {
    }

    void display(ostream& os) const override {
        os << "Mule: " << name << ", " << birthYear
            << ", Nickname: " << nickname << '\n';
    }

    bool matchesCriteria(const string& parameter) const override {
        return nickname == parameter ||            // Перевірка прізвиська
            Horse::matchesCriteria(parameter) || // Властивості Horse
            Donkey::matchesCriteria(parameter);  // Властивості Donkey
    }


};

#endif
