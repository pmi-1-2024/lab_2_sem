#ifndef SPECIAL_T_H
#define SPECIAL_T_H

#include "Transport.h"

template<typename T>
class SpecialTransport : public Transport<T> {
private:
    string specialCond;

public:
    SpecialTransport() : Transport<T>(), specialCond("") {}
    SpecialTransport(T c, string d, double p, string cond) : Transport<T>(c, d, p), specialCond(cond) {}

    void setConditions(string cond) { specialCond = cond; }
    string getConditions() const { return specialCond; }

    void discount() {
        if (specialCond == "medical" || specialCond == "Medical") {
            this->price *= 0.9;
        }
    }

    friend ostream& operator<<(ostream& os, const SpecialTransport<T>& s) {
        os << "Cargo: " << s.cargo << ", Destination: " << s.dest << ", Price: " << s.price << ", Special Conditions: " << s.specialCond;
        return os;
    }

    friend istream& operator>>(istream& is, SpecialTransport<T>& s) {
        is >> s.cargo >> s.dest >> s.price >> s.specialCond;
        return is;
    }
};

#endif