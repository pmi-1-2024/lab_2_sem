#pragma once
#ifndef SPECIAL_TRANSPORT_H
#define SPECIAL_TRANSPORT_H

#include "transport.h"

template <typename T>
class SpecialTransport : public Transport<T> {
    string condition;

public:
    SpecialTransport();
    SpecialTransport(T c, string d, double cost, string cond);

    double calculateDiscountedCost() const override;
    void print() const override;
    string getCondition() const;
};

#include "special_transport.cpp"

#endif 