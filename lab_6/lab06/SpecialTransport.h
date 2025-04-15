#pragma once
#include "Transport.h"

template<typename T>
class SpecialTransport : public Transport<T> {
private:
    bool hasSpecialConditions;
public:
    SpecialTransport(T cargo, const char* destination, double cost, bool special);
    double calculateDiscount(double percent) const override;
    void print() const override;
};